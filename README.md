# General-Sudoku-Solver

A general-purpose Sudoku solver implemented in C++ that supports boards of various sizes — including 9x9, 16x16, and 25x25. It uses the Dancing Links (DLX) algorithm, an efficient implementation of Donald Knuth’s Algorithm X, to solve the puzzle by modeling it as an Exact Cover problem.


What It Does
- Solves standard and extended Sudoku puzzles (e.g., 9x9, 16x16, 25x25).
- Models Sudoku rules as an exact cover problem.
- Uses DLX for efficient backtracking and solution pruning.
- Supports alphanumeric boards (e.g., A–F for 16x16).


Algorithms Used
- **Exact Cover using DLX (Dancing Links)** — Core logic to solve Sudoku via efficient constraint satisfaction.
- **Breadth-First Search (BFS)** — Used for pathfinding in internal logic or variant features.
- **Path Reconstruction via Parent Pointers** — Rebuilds valid paths from endpoints (used in search processes).

  
How It Works
Each Sudoku puzzle is translated into a constraint matrix where a valid solution must:

1. Fill each cell with one number.
2. Ensure each number appears once per row.
3. Ensure each number appears once per column.
4. Ensure each number appears once per box.

DLX finds a subset of rows (number placements) that satisfies all four constraints simultaneously.

Input Format
- The puzzle is read via standard input.
- Each line corresponds to a row of the board.
- Values are space-separated.
- Use `0` to indicate blank cells.
- For sizes > 9, use uppercase letters (e.g., A = 10, B = 11, etc.).


Practical Use: Showcases expertise in complex problem solving, with direct applications in optimization, compilers, and AI reasoning systems.
