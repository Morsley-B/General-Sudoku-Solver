General-Sudoku-Solver
This project is a general-purpose Sudoku solver implemented in C++. It supports solving standard 9x9 puzzles as well as larger boards like 16x16 and 25x25, using the Dancing Links (DLX) algorithm — an efficient implementation of Donald Knuth’s Algorithm X for solving exact cover problems.

What It Does

- Solves Sudoku puzzles of various sizes (e.g., 9x9, 16x16, 25x25).
- Utilizes an exact cover formulation for Sudoku constraints.
- Efficiently searches for valid solutions using Dancing Links.
- Supports alphanumeric symbols for boards larger than 9x9 (e.g., A-F for 16x16).

 Algorithms
- Exact Cover using DLX (Dancing Links) — Efficient algorithm for solving constraint satisfaction problems.
- Breadth-First Search (BFS) — Used for some internal validation paths or optional safety logic.
- Path Reconstruction using Parent Pointers — Builds the solution path from the end node back to the start in BFS-style traversals.

- The solver treats Sudoku as an exact cover problem, where each number placement must satisfy four constraints:
1. Each cell contains exactly one number.
2. Each number appears once per row.
3. Each number appears once per column.
4. Each number appears once per box.

The program builds a constraint matrix representing all possible valid placements and uses DLX to find a valid subset of placements that satisfies all constraints.

The Input format :
Sudoku board via standard input (rows with space-separated values; 0 for blanks)
