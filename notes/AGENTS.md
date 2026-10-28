# Lecture note formatting

For new exercises and future lecture notes, use a light red exercise box:
`colback=exercisebg` (HTML `FDEAEA`) and
`colframe=exerciseframe` (HTML `B54040`).
Use the `exercise` environment with this style. Preserve other established
box styling, including padding and theorem numbering.

This is the default going forward; do not recolor older lecture notes unless
the user requests it.

Remarks use a light purple box: `colback=remarkbg` (HTML `F3EEFB`) and
`colframe=remarkframe` (HTML `9B7FC9`), with the same padding as the other
boxes and `before upper={\setlength{\parskip}{0.5em}}`.

For future lectures, remark headings use bold upright text for both
`Remark` and the full parenthesized title, for example
**Remark (The case of a disc).** The body stays in normal upright text,
and remarks remain unnumbered. Use the following `amsthm` style, as in
Lecture 21:

```latex
\newtheoremstyle{boldremark}
  {3pt}{3pt}{\normalfont}{}{\bfseries}{.}{.5em}
  {\thmname{#1}\thmnumber{ #2}\thmnote{ (#3)}}
\theoremstyle{boldremark}
\newtheorem*{remark}{Remark}
\theoremstyle{remark}
```

Keep the light purple box styling above. Apply this heading format to new
and future lectures; do not restyle existing lectures unless requested.
