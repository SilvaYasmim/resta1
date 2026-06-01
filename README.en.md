# Resta 1 — Peg Solitaire

## About the project

This project was developed as part of the C/C++ Programming Fundamentals course,
integrated in the Java training program at IEFP. The choice of game, however, was personal:
Peg Solitaire was taught to me by my great-grandmother, who raised me, and who had a special
passion for patience games. This month she turns 100 years old — this project is, in a way,
a tribute to her.

## What is Peg Solitaire

Peg Solitaire is a single-player puzzle game. The objective is simple:
starting from an almost full board, you must eliminate pegs until only one remains.
Pegs are eliminated by "jumping" over each other — and that's where the challenge lies.
It seems easy, but requires strategy and anticipation.

## Rules

- The board starts with 32 pegs and a single empty space in the center.
- The board has a cross ("+") shape.
- A move consists of jumping a peg over an adjacent one, horizontally or vertically,
  into an empty space — the jumped peg is removed.
- Only one peg can be jumped at a time.
- Diagonal moves are not allowed.
- The game ends when no more moves are possible.
- **You win** if only one peg remains on the board.
- **You lose** if more than one peg remains with no moves possible.

## How to compile

You need GCC and ncurses installed.

**Linux/macOS:**
```bash
gcc main.c game.c score.c -o resta1 -lncurses
```

**Windows (MSYS2 UCRT64):**
```bash
gcc main.c game.c score.c -o resta1 -I/ucrt64/include/ncurses -L/ucrt64/lib -lncursesw
```

To run:
```bash
./resta1
```

## How to play

When the program starts, a menu appears with options: Play, How to Play, View History and Exit.

The board is displayed in the terminal with row and column coordinates (0-6).
To make a move, enter the origin and destination coordinates:

Origin (row column): 3 5
Destination (row column): 3 3

The peg jumps over the adjacent peg and removes it from the board.

## Project structure
resta1/
├── main.c        → entry point, main menu and game loop
├── game.c        → game logic (board, moves, validation)
├── game.h        → declarations and constants for game.c
├── score.c       → save and display score history
├── score.h       → declarations for score.c
├── README.md     → documentation in Portuguese
├── README.en.md  → documentation in English
├── PLANNING.md   → function and variable planning
└── LOG.md        → development diary

## Author

**Yasmim Silva**  
Java Training — IEFP  
[GitHub](https://github.com/SilvaYasmim)