#!/usr/bin/env python3
"""Assemble the published site into _site/.

Scans notes/ and hw/ for compiled PDFs and turns the matching placeholder
cells in index.html into real links. A lecture with no PDF yet keeps its
dash, so the site never shows a dead link.
"""
import html as html_mod
import re
import shutil
from datetime import date
from pathlib import Path

ROOT = Path(__file__).parent.resolve()
SITE = ROOT / "_site"

if SITE.exists():
    shutil.rmtree(SITE)
SITE.mkdir()

html = (ROOT / "index.html").read_text(encoding="utf-8")
linked = []
syllabus = ROOT / "syllabus.pdf"


def link_cell(attr, pdf_path_for):
    """Replace <td {attr}="NN">...</td> with a link when the PDF exists."""
    def repl(m):
        num = m.group(1)
        rel = pdf_path_for(num)
        if (ROOT / rel).exists():
            linked.append(rel)
            return f'<td {attr}="{num}"><a href="{rel}">PDF</a></td>'
        return m.group(0)
    return repl


html = re.sub(r'<td data-lecture="(\d+)">.*?</td>',
              link_cell("data-lecture", lambda n: f"notes/lecture-{n}.pdf"),
              html)

html = re.sub(r'<td data-hw="(\d+)">.*?</td>',
              link_cell("data-hw", lambda n: f"hw/hw-{n}.pdf"),
              html)

html = re.sub(r'<td data-hw-sol="(\d+)">.*?</td>',
              link_cell("data-hw-sol", lambda n: f"hw/hw-{n}-solutions.pdf"),
              html)


# --- announcements --------------------------------------------------------

def inline(text):
    """Escape, then apply the small subset of Markdown we support."""
    out = html_mod.escape(text)
    out = re.sub(r"\[([^\]]+)\]\((?!javascript:)([^)\s]+)\)",
                 r'<a href="\2">\1</a>', out, flags=re.I)
    out = re.sub(r"\*\*([^*]+)\*\*", r"<strong>\1</strong>", out)
    out = re.sub(r"(?<!\*)\*([^*]+)\*(?!\*)", r"<em>\1</em>", out)
    return out


def parse_announcements(path):
    """Return [(date, [paragraph, ...]), ...] newest first."""
    if not path.exists():
        return []
    entries, current = [], None
    for line in path.read_text(encoding="utf-8").splitlines():
        heading = re.match(r"##\s*(\d{4})-(\d{2})-(\d{2})\s*$", line)
        if heading:
            current = (date(*map(int, heading.groups())), [])
            entries.append(current)
            continue
        if line.startswith("#") or current is None:
            continue
        if line.strip():
            if current[1] and current[1][-1] is not None:
                current[1][-1] += " " + line.strip()
            else:
                current[1].append(line.strip())
        elif current[1]:
            current[1].append(None)          # paragraph break marker
    cleaned = [(d, [p for p in paras if p]) for d, paras in entries]
    return sorted(cleaned, key=lambda e: e[0], reverse=True)


announcements = parse_announcements(ROOT / "announcements.md")

if announcements:
    blocks = []
    for i, (when, paragraphs) in enumerate(announcements):
        cls = "announce latest" if i == 0 else "announce"
        body = "\n        ".join(f"<p>{inline(p)}</p>" for p in paragraphs)
        blocks.append(
            f'      <div class="{cls}">\n'
            f'        <time datetime="{when.isoformat()}">'
            f'{when.strftime("%A, %B %-d, %Y")}</time>\n'
            f'        {body}\n'
            f'      </div>'
        )
    rendered = ('    <div class="announce-list">\n'
                + "\n".join(blocks) + "\n    </div>")
else:
    rendered = ('    <p class="announce-empty">'
                'No announcements yet.</p>')

html = html.replace("<!--ANNOUNCEMENTS-->", rendered)


# --- syllabus -------------------------------------------------------------

card_tag = (f'<a class="doc-card" href="syllabus.pdf" target="_blank" '
            f'rel="noopener">' if syllabus.exists()
            else '<div class="doc-card" aria-disabled="true">')
card_close = '</a>' if syllabus.exists() else '</div>'
card_status = ('PDF &#183; available' if syllabus.exists()
               else 'PDF &#183; <span class="tba">not yet posted</span>')
card_cta = 'Download &#8594;' if syllabus.exists() else 'Coming soon'
syllabus_card = f'''{card_tag}
        <span class="doc-icon" aria-hidden="true">
          <svg width="22" height="22" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="1.6" stroke-linecap="round" stroke-linejoin="round">
            <path d="M14 2H6a2 2 0 0 0-2 2v16a2 2 0 0 0 2 2h12a2 2 0 0 0 2-2V8z"></path>
            <path d="M14 2v6h6"></path>
          </svg>
        </span>
        <span class="doc-text">
          <span class="doc-title">Honors Complex Variables syllabus</span>
          <span class="doc-sub">{card_status}</span>
        </span>
        <span class="doc-cta">{card_cta}</span>
      {card_close}'''
html = html.replace("<!--SYLLABUS-CARD-->", syllabus_card)

(SITE / "index.html").write_text(html, encoding="utf-8")

# Copy the compiled PDFs and the syllabus alongside it.
for folder in ("notes", "hw"):
    src = ROOT / folder
    if not src.is_dir():
        continue
    pdfs = sorted(src.glob("*.pdf"))
    if pdfs:
        (SITE / folder).mkdir(exist_ok=True)
        for pdf in pdfs:
            shutil.copy2(pdf, SITE / folder / pdf.name)

if syllabus.exists():
    shutil.copy2(syllabus, SITE / "syllabus.pdf")

print(f"Built _site/ with {len(announcements)} announcement(s) "
      f"and {len(linked)} linked PDF(s):")
for rel in linked:
    print(f"  {rel}")
if not linked:
    print("  (none yet - add .tex files to notes/ or hw/)")
