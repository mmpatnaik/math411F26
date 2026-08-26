# MATH 411: Honors Complex Variables — course site

Source for the course website and lecture notes. Pushing to `main` compiles
every `.tex` file and republishes the site automatically.

## Repository layout

```
index.html              the course site (edit for schedule/policy changes)
announcements.md        class announcements; add new entries at the top
build.py                assembles _site/, injecting announcements and PDF links
notes/lecture-NN.tex    lecture notes, one file per lecture
hw/hw-NN.tex            problem sets
hw/hw-NN-solutions.tex  solutions (see the note below before adding these)
syllabus.pdf            drop your syllabus here; it is copied as-is
```

`NN` is zero-padded: `lecture-01.tex`, `lecture-02.tex`, … `lecture-36.tex`.
The names matter — that is how the build matches a PDF to its row in the table.

## The workflow you'll actually use

Add or edit a `.tex` file, then:

```bash
git add notes/lecture-07.tex
git commit -m "Lecture 7 notes"
git push
```

About a minute later the PDF is live and the Notes cell for lecture 7 has
turned into a link. Lectures without a PDF keep their dash, so the site never
shows a dead link. You do not need to touch `index.html` to publish notes.

## Posting an announcement

Add an entry at the **top** of `announcements.md`:

```markdown
## 2026-09-18
No class this Friday — I'm away at a conference.

Lecture 8 will be rescheduled; details to follow.
```

Then commit and push. Entries are sorted by date automatically (so it doesn't
actually matter where in the file you put them), the newest is highlighted, and
older ones stay below as a running log. Blank lines start a new paragraph, and
you can use `**bold**`, `*italic*`, and `[links](https://example.com)` —
including in-page ones like `[Problem sets](#homework)`.

Nothing is ever deleted unless you delete it, so the section doubles as the
archive of everything you've sent the class.

### A note on privacy

Announcements are **public** — GitHub Pages serves static files and runs no
server-side code, so a JavaScript password would ship to the browser alongside
the content it claims to protect. Anything you wouldn't post publicly (grades,
exam contents) belongs on eClass. If you later need genuine access control on
this site, put a custom domain behind Cloudflare Access.

## One-time setup

**1. Create the repo and push.**

```bash
cd math411F26
git init -b main
git add .
git commit -m "Initial course site"
git remote add origin https://github.com/mmpatnaik/math411F26.git
git push -u origin main
```

**2. Turn on Pages.** In the repo: Settings → Pages → under "Build and
deployment", set Source to **GitHub Actions**. (Not "Deploy from a branch".)

**3. Watch the first build.** The Actions tab will show it running; it takes a
few minutes the first time while the TeXLive image downloads. When it finishes,
your site is at `https://mmpatnaik.github.io/math411F26/`.

**4. Point ualberta at it.** Upload the prepared `ualberta-redirect.html` once:

```bash
scp ualberta-redirect.html patnaik@gpu.srv.ualberta.ca:public_html/index.html
```

You'll be prompted for your CCID password. That's the last time you need to
touch the ualberta server — anyone visiting your old URL now lands on the
current site.

## Testing locally

To preview the website without compiling lecture notes:

```bash
python3 build.py
open _site/index.html
```

To preview a lecture PDF locally, compile a real lecture file with `latexmk`
before running `build.py`.

## Notes

- **Solutions are public.** Anything in this repo is served on a public
  website. If you don't want solutions or exam materials visible, keep them
  out of the repo entirely and post them to eClass instead.
- **The Homework table's "Covers" column** is intentionally marked TBA until
  the MATH 411 problem-set topics are finalized.
- **Cache.** Students who opened a PDF before you updated it may see the old
  copy. Putting `\date{Compiled \today}` on the title page makes the version
  obvious at a glance.
