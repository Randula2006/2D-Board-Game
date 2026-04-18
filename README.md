# 2D Board Game (Labyrinth)

## Overview

Labyrinth is a terminal-based 2D board game written in C. The game loads a map from a text file, renders a colored board in the terminal, and runs a full game loop with player movement, enemy movement, win/loss checks, and undo support.

The executable name is `labyrinth`.

## Implemented Features

- Load a map from file (`rows`, `cols`, then tile values).
- Render the board with borders and ANSI colors.
- Move the player with keyboard controls.
- Enforce movement rules (walls, boundaries, and locked goal until treasure is collected).
- Move an enemy with direction-aware randomized behavior.
- Detect win and loss conditions.
- Undo to the previous saved state using a linked-list snapshot stack.

## Controls

- `w`: move up
- `s`: move down
- `a`: move left
- `d`: move right
- `u`: undo last saved move

## Game Rules

- The player starts at tile `4` (`P`).
- The enemy starts at tile `5` (initially displayed as `<`).
- The treasure is tile `3` (`T`).
- The goal is tile `2` (`G`).
- The player wins only after collecting treasure and then reaching the goal.
- The player loses if the enemy reaches the same cell as the player.

Movement behavior:

- Invalid player moves are blocked (out of bounds, into a wall, or into the goal before collecting treasure).
- A snapshot is saved before movement input, then removed if that movement is invalid.
- Enemy movement runs only after a valid player move:
  - 2 moves when treasure is not collected.
  - 3 moves when treasure is collected.

## Tile Encoding

Map files use integer tile IDs:

- `0` = empty space
- `1` = wall
- `2` = goal (`G`)
- `3` = treasure (`T`)
- `4` = player (`P`)
- `5` = enemy (stored as facing symbol in grid, starts as `<`)

## Map File Format

First line:

```text
<rows> <cols>
```

Then provide `rows x cols` integers.

Example (`map.txt`):

```text
10 20
4 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 3
...
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 2
```

## Build

### Option 1: Makefile (Linux/macOS/WSL/Git Bash)

```bash
make
```

### Option 2: direct GCC command

```bash
gcc -Wall -ansi -pedantic main.c map.c player.c enemy.c terminal.c linked_list.c game.c random.c -o labyrinth
```

## Run

```bash
./labyrinth map.txt
```

Usage:

```text
./labyrinth <map_file>
```

If your executable is `labyrinth.exe` (Windows toolchain):

```bash
./labyrinth.exe map.txt
```

## Platform Notes

- The project uses POSIX terminal APIs (`termios`, `nanosleep`) and shell commands (`clear`, `tput cup`).
- Best compatibility on Windows is through WSL or Git Bash.
- Plain PowerShell or CMD may not support all terminal features exactly the same way.

## Project Files

- `main.c`: program entry, argument handling, game loop orchestration.
- `map.c`, `map.h`: map loading, rendering, color helpers, map memory management.
- `player.c`, `player.h`: player movement validation and treasure collection.
- `enemy.c`, `enemy.h`: enemy facing/rotation logic and randomized movement.
- `game.c`, `game.h`: win/lose game state checks.
- `linked_list.c`, `linked_list.h`: undo snapshot stack (save/restore/free).
- `terminal.c`, `terminal.h`: input buffering controls and key input.
- `random.c`, `random.h`: random seed and random number utility.
- `map.txt`: sample map.
- `makefile`: build and clean targets.

## Cleanup

```bash
make clean
```
