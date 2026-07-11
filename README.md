# Algolymp Summer School $-$ Clasa a IX-a

Acest modul face parte din **Algolymp Summer School** și urmează [programa Olimpiadei Naționale de Informatică]([url](https://cdn.sepi.ro/oni2026/Programa_pentru_olimpiada_de_informatica_gimnaziu_si_liceu_2025-2026.pdf)) din România.
## Programa

| # | Topic |
|---|------|
| [01](lessons/01-divisibility/lesson.pdf) | **Divizibilitate**<br>Ciurul lui Eratostene · Descompunere în factori primi · Suma și numărul divizorilor |
| [02](lessons/02-euclid-exponentiation/lesson.pdf) | **Algoritmul lui Euclid \| Exponențiere rapidă** |
| [03](lessons/03-number-systems-bitwise/lesson.pdf) | **Sisteme de numerație \| Operații pe biți** |
| [04](lessons/04-sorting-bubble-stl-counting/lesson.pdf) | **Algoritmi de sortare**<br>Bubble · Selection · Insertion · STL · Counting Sort |
| [05](lessons/05-binary-search/lesson.pdf) | **Căutare binară**<br>Varianta clasică · Variații · STL · Complexitate · Căutare binară pe rezultat |
| 06 | **Funcții \| Algoritmi pe șiruri**<br>Fibonacci · Elementul majoritar · Subsecvența de sumă maximă |
| 07 | **Tablouri bidimensionale**<br>Parcurgeri · Împărțirea în zone · Simulări |
| 08 | **Sume parțiale și șmenul lui Mars**<br>Pe șiruri (1D) · Pe matrici (2D) |
| 09 | **Tehnica Two Pointers**<br>Interclasarea tablourilor · Operații cu mulțimi |
| 10 | **Tipuri de date non-omogene**<br>Tipul struct · Fișiere text · Structuri de date din STL |
| 11 | **Algoritmi Greedy**<br>Problema spectacolelor · Diverse probleme |
| 12 | **Funcția Möbius \| Principiul includerii și excluderii** |
| 13 | **Backtracking**<br> Generarea elementelor combinatoriale |
| 14 | **Simulare OJI** |

## Structură

```
lessons/
  XX-topic-name/
    lesson.tex    — sursă LaTeX
    lesson.pdf    — PDF compilat (gata de descărcat)
resources/
  style.sty       — stil LaTeX comun
  template.tex    — șablon gol pentru lecții noi
```

## Compilare LaTeX

```bash
pdflatex lesson.tex
```

Necesită o distribuție TeX standard (TeX Live / MiKTeX).
