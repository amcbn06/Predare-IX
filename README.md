# Algorithms & Data Structures — Grade 9

Weekly lessons covering algorithms and data structures for 9th grade students.

## Syllabus

| # | Topic |
|---|-------|
| [01](lessons/01-divisibility/lesson.pdf) | Divisibility: Sieve of Eratosthenes / Prime factorization / Sum and number of divisors |
| [02](lessons/02-euclid-exponentiation/lesson.pdf) | Euclid's Algorithm / Fast exponentiation |
| [03](lessons/03-number-systems-bitwise/lesson.pdf) | Number systems: Conversions / Memory representation / Bitwise operations |
| 04 | Sorting algorithms: Bubble Sort / STL sort / Counting Sort |
| 05 | Binary search |
| 06 | Fibonacci sequence / Algorithm for determining the majority element |
| 07 | Introduction to two-dimensional arrays: Traversals / Partitioning into zones |
| 08 | Partial sums 1D/2D / Difference Arrays 1D/2D |
| 09 | Two-pointers technique |
| 10 | Non-homogeneous data types: Struct / Data structures from STL library |
| 11 | Greedy algorithms: The interval scheduling problem / Various problems |
| 12 | Mobius Function & Inclusion and Exclusion Principle |
| 13 | Backtracking: Functions from STL / Generation of combinatorial elements |

## Structure

```
lessons/
  XX-topic-name/
    lesson.tex    — LaTeX source
    lesson.pdf    — compiled PDF (ready to download)
resources/
  style.sty       — shared LaTeX style
  template.tex    — blank lesson template
```

## Compiling LaTeX

```bash
pdflatex lesson.tex
```

Requires a standard TeX distribution (TeX Live / MiKTeX).
