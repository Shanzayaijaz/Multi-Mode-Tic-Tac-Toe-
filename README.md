# Multi-Mode-Tic-Tac-Toe-

## Overview

This is a console-based **Tic-Tac-Toe game** implemented in **C** with support for:
- Classic 2-player mode
- AI mode (Player vs Computer)
- 3-player extended mode (4x4 board)
- Scoreboard tracking using file I/O

The game is designed to be played in a Windows terminal and utilizes functions like `gotoxy`, `Beep`, and `system("cls")` for better interactivity and aesthetics.

---

## Game Modes

### 1. **2-Player Classic Mode**
- 3x3 board
- Players choose between X and O
- Win by aligning three symbols in a row, column, or diagonal

### 2. **AI Mode**
- Human vs Computer
- The computer plays with simple logic
- Board state is updated after each move
- Scoreboard logs the winner and loser

### 3. **3-Player Mode**
- 4x4 board
- Players use symbols X, Y, and Z
- Win by making four in a row
- Supports score tracking

---

## Features

- **Scoreboard Logging**  
  Maintains game results in a `scoreboard.txt` file.

- **Dynamic Board Drawing**  
  Boards are rendered using formatted console output for clarity.

- **Input Validation**  
  Ensures players make valid moves (no overwriting, correct turn, etc.)

- **ASCII Art Loader**  
  Simple animated loading screen using beeps and special characters.

- **Windows Console Support**  
  Uses Windows-specific libraries (`windows.h`, `conio.h`) for cursor control and audio.

---

## How to Compile

> This game is designed for Windows.

Use any C compiler that supports Windows headers.  
Example using GCC (MinGW):

```bash
gcc -o tictactoe tictactoe.c -lwinmm
```

Then run the game:

```bash
tictactoe.exe
```

