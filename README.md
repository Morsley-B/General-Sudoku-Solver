# General-Sudoku-Solver
A high performance , scalable Sudoku solver that uses the Dancing Links(DLX) algorithm for solving  a 9x9, 16x16, 25x25, and larger Sudoku Boards

What It Does

- Solves Sudoku puzzles of various sizes (e.g., 9x9, 16x16, 25x25).
- Utilizes an exact cover formulation for Sudoku constraints.
- Efficiently searches for valid solutions using Dancing Links.
- Supports alphanumeric symbols for boards larger than 9x9 (e.g., A-F for 16x16).

- The solver treats Sudoku as an exact cover problem, where each number placement must satisfy four constraints:
1. Each cell contains exactly one number.
2. Each number appears once per row.
3. Each number appears once per column.
4. Each number appears once per box.

The program builds a constraint matrix representing all possible valid placements and uses DLX to find a valid subset of placements that satisfies all constraints.

The Input format :
The puzzle is read from standard input. Each line represents a row of the grid, with numbers separated by spaces.
