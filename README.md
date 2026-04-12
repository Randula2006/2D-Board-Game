# 2D Board Game (Labyrinth)

## Overview

This project is a terminal-based C game prototype that loads a 2D map from a text file and renders it with simple colors.

At the current stage, the implemented flow is:

1. Read a map file.
2. Parse numeric tile values into game objects.
3. Print the board with borders and ANSI-colored symbols.

The executable name is `labyrinth`.

## Current Status

Implemented now:

- Map loading from file (`rows`, `cols`, then tile values).
- Conversion from tile IDs to display characters.
- Colored terminal rendering with border.
- Tracking coordinates for player, enemy, treasure, and goal.

Scaffolding exists but is not yet implemented:

- `enemy.c/.h`
- `player.c/.h`
- `game.c/.h`
- `linked_list.c/.h`
- `random.c/.h`
- `terminal.c/.h`

## Tile Encoding

Map files use integer tile IDs:

- `0` = empty space
- `1` = wall
- `2` = goal (`G`)
- `3` = treasure (`T`)
- `4` = player (`P`)
- `5` = enemy (`<`)

## Map File Format

The first line defines dimensions:

```text
<rows> <cols>
```

Then provide `rows x cols` integers.

Example (from `map.txt`):

```text
10 20
4 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 3
...
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 2
```

## Build

### Option 1: make (Linux/macOS/WSL/Git Bash)

```bash
make
```

### Option 2: direct GCC command

```bash
gcc -Wall -ansi -pedantic main.c map.c -o labyrinth
```

## Run

```bash
./labyrinth map.txt
```

If your executable is `labyrinth.exe` (Windows toolchain), run:

```bash
./labyrinth.exe map.txt
```

## Notes for Windows

- The renderer uses terminal commands such as `clear` and `tput` for screen control and ANSI escape colors.
- Best compatibility is through WSL or Git Bash.
- If running in plain PowerShell, behavior may differ depending on terminal capabilities.

## Project Files

- `main.c`: Entry point and argument handling.
- `map.c`, `map.h`: Core implemented logic for map parsing, rendering, and memory management.
- `map.txt`: Sample map.
- `makefile`: Current build file (builds the implemented modules).

## Cleanup

```bash
make clean
```

## Future Work

- Add player movement and input handling.
- Add enemy movement/AI.
- Implement win/lose game loop rules.
- Integrate randomization and linked-list utilities where needed.
