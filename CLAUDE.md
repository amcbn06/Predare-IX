# CLAUDE.md — Ghid pentru asistarea lecțiilor Algolymp Predare-IX

## Publicul țintă

Elevii de clasa a 9-a **abia la începutul informaticii**. Mulți nu cunosc:
- Notația de complexitate $O(\ldots)$
- Funcții în C++
- STL (`vector`, `pair`, `map` etc.)
- Logaritmul (nici măcar $\log_2$)

**Regulă generală:** ori de câte ori apare un concept din lista de mai sus pentru prima dată într-o lecție, adaugă o notă pentru începători și trimite la slide-ul de Resurse.

---

## Structura fiecărei lecții

### Notă pentru începători (`\beginnote`)

Definită în preambulul fiecărui `lesson.tex`:

```latex
\newcommand{\beginnote}[1]{%
  \vfill
  {\footnotesize\textcolor{gray}{\textit{$\triangleright$ #1 (vezi slide-ul \emph{Resurse})}}}%
}
```

Folosește `\beginnote{...}` **la baza slide-ului** (înainte de `\end{frame}`) ori de câte ori introduci:
- complexitate $O(\ldots)$
- o funcție C++
- un tip STL (`vector`, `pair` etc.)
- logaritmul

### Slide de Resurse

Fiecare lecție trebuie să aibă o secțiune `\section{Resurse}` la final cu două slide-uri:

1. **Complexitate + Funcții** — linkuri către pbinfo.ro și cppreference
2. **STL + Logaritm + Probleme de antrenament** — pbinfo.ro, cppreference, definiție intuitivă

Surse recomandate (în română, accesibile):
- `infoas.ro/lectie/91/complexitatea-unui-algoritm-timp-si-spatiu-in-c` — complexitate (RO)
- `bigocheatsheet.com` — tabel vizual complexități
- `pbinfo.ro/articole/23702/standard-template-library-stl` — STL în română
- `cppreference.com` — documentație C++ și STL (EN)

**IMPORTANT:** Nu inventa URL-uri specifice fără să știi că există. Folosește doar linkurile de mai sus sau linkul de bază al site-ului + instrucțiunea de căutare.

---

## Reguli LaTeX

### Caractere speciale — NU folosi Unicode direct

| În loc de | Folosește |
|-----------|-----------|
| `—` (em dash) | `\textemdash{}` |
| `✓` | `\checkmark` |
| `✗` | `$\times$` |
| `⚠️` | `\alert{!}` |
| `10^6` în text | `$10^6$` |

### Linie de cod (em dash)

**NICIODATĂ** `—` direct în cod LaTeX. Întotdeauna `\textemdash{}`.

### Diacritice în `lstlisting`

**Nu** folosi diacritice românești (ă, î, â, ș, ț) în comentarii din interiorul blocurilor `lstlisting` sau `\lstinline`. Comentariile din cod se scriu fără diacritice:

```cpp
// (factor prim, exponent)   <- corect
// (număr prim, exponent)    <- GREȘIT în lstlisting
```

### Slide-uri cu cod

- Folosește `[fragile, shrink]` pentru orice frame cu `lstlisting`
- Cod inline: `\lstinline|...|`
- Centrare cod: învelește `lstlisting` în `\begin{center}...\end{center}`

### Overflow pe slide

Dacă conținutul depășește marginea de jos, adaugă opțiunea `[shrink]` la `\begin{frame}`.

---

## Reguli de complexitate

### O(n/2) = O(n)

Constantele dispar în notația Big-O. **Nu** scrie `O(n/2)` ca și cum ar fi o clasă de complexitate diferită de `O(n)`.

Formulare corectă pentru îmbunătățiri cu factor constant:

> ❌ „optimizare la $O(n/2)$"  
> ✅ „reducere la $\lfloor n/2 \rfloor$ iterații"

### Ciurul lui Eratostene (varianta cu `2 * i`)

Implementarea standard care pornește marcarea de la `j = 2 * i` se prezintă cu complexitate **$O(n \log n)$** — justificabilă prin seria armonică ($\sum_{i=1}^{n} n/i \approx n \ln n$), familiară elevilor.

**Nu** folosi $O(n \log \log n)$ pentru această variantă în context didactic — necesită Teorema lui Mertens, care e prea avansată pentru clasa a 9-a.

$O(n \log \log n)$ exact se obține doar dacă se iterează **strict** peste numere prime; poate fi menționat ca notă avansată, dar nu ca rezultat principal.

---

## Definiții corecte (matematică)

### Divizori proprii și improprii

> **Divizorii proprii** ai lui $n$ sunt toți divizorii săi **diferiți de $1$ și de $n$**.  
> **Divizorii improprii** ai lui $n$ sunt $1$ și $n$ însuși.

Exemplu: $n = 12$ → proprii: $\{2, 3, 4, 6\}$, improprii: $\{1, 12\}$.

### Complexitatea spațiului pentru factorizare

Funcția `factorize` are spațiu $O(\log n)$ deoarece un număr $n$ are cel mult $\log_2 n$ factori primi distincți. Menționează explicit: „$\log_2(10^6) \approx 20$" pentru intuiție.

---

## Overflow în C++

### `d * d <= n`

Când $n$ se apropie de `INT_MAX` ($2^{31}-1 \approx 2.1 \cdot 10^9$), produsul `d * d` poate depăși `INT_MAX` chiar dacă $n$ încape în `int` (apare când $d \approx \sqrt{\texttt{INT\_MAX}} \approx 46341$).

Soluție standard: `(long long)d * d <= n`.

Aplică acest cast oriunde apare `d * d <= n` sau `p * p <= n` în cod.

---

## Structura pedagogică recomandată (Lecția 01 \textemdash{} Divizibilitate)

Ordinea care ajută elevii să conecteze conceptele:

1. Divizibilitate (definiție, exemple)
2. Divizori proprii/improprii
3. Găsirea divizorilor: $O(n)$ \textemdash{} $O(n/2)$ iterații \textemdash{} $O(\sqrt{n})$
4. Numărul $\tau(n)$ și suma $\sigma(n)$ divizorilor (direct $O(\sqrt{n})$)
5. Numere prime și compuse (motivat de: „ce numere au exact 2 divizori?")
6. Verificarea primalității $O(\sqrt{n})$
7. Factorizare în factori primi
8. De la factorizare la $\tau(n)$, $\sigma(n)$ prin formule
9. Ciurul lui Eratostene (motivat de ineficiența $O(n\sqrt{n})$)
10. Extensie ciur pentru $\tau$, $\sigma$
11. Recapitulare complexități
12. Resurse

---

## Checklist înainte de compilare

- [ ] Niciun `—` direct în cod (înlocuit cu `\textemdash{}`)
- [ ] Niciun caracter Unicode special în afara blocurilor de text LaTeX (✓ ✗ ⚠️)
- [ ] Puteri/exponenți în text sunt în math mode (`$10^6$`, nu `10^6`)
- [ ] Fără diacritice în `lstlisting`
- [ ] Fiecare frame cu `lstlisting` are `[fragile]`
- [ ] Slide-urile care depășesc marginea au `[shrink]`
- [ ] `\beginnote` prezent la prima apariție a complexității, funcțiilor, STL, logaritmului
- [ ] Slide Resurse prezent la finalul lecției
- [ ] Acoladele din cod sunt echilibrate (verifică manual funcțiile `is_prime`, `factorize` etc.)
