## Multi-Mode Tic-Tac-Toe

### Overview

This is a console-based Tic-Tac-Toe game in C designed for Windows terminals. It supports:

* 2-player classic mode
* AI mode (Player vs Computer)
* 3-player mode (4x4 board)
* Scoreboard tracking with file I/O

The game uses Windows-only functions like `gotoxy`, `Beep`, and `system("cls")` for an interactive experience.

---

### Game Modes

#### 1. Classic 2-Player Mode

* **Board:** 3x3
* **Players:** Choose between `X` and `O`
* **Win Condition:** 3 in a row (row, column, or diagonal)
* **Post-Game:** Winner plays against AI

#### 2. AI Mode

* **Board:** 3x3
* **Players:** Human vs Computer
* **AI Logic:**

  * Tries to win
  * If not possible, tries to block the player
  * Otherwise, plays a random move
* **Implementation:** Uses recursive logic instead of loops for smarter decision-making
* **Tracking:** Results are saved in `scoreboard.txt`

#### 3. 3-Player Mode (Extended)

* **Board:** 4x4 grid
* **Players:** Symbols `X`, `Y`, and `Z`
* **Win Condition:** 4 in a row (horizontal, vertical, or diagonal)
* **Tracking:** Stores winner’s name and player number in `scoreboard.txt`

---

### Features

#### Scoreboard Logging

* Uses `scoreboard.txt` to store game outcomes
* Tracks:

  * Winner and loser in AI mode
  * Winning player in 3-player mode

#### Interactive Terminal UI

* Cursor movement using `gotoxy`
* Clears screen after each move with `system("cls")`
* Beep sounds during loading animation for feedback

#### AI Uses Recursion

* `aiMove()` rewritten to use recursive logic
* Checks for:

  * Winning opportunities
  * Blocking opponent
  * Choosing a random move if needed

#### Input Validation

* Prevents overwriting existing moves
* Validates symbol choices and input range
* Ensures proper player turns in all modes

#### Extras

* `load()` function shows an animated loading screen with beeps
* Console color changes using `system("COLOR Fx")` based on game state

---

### How to Compile

> This game is designed for Windows.

Use a C compiler that supports Windows headers. Example using **GCC (MinGW)**:

```bash
gcc -o tictactoe tictactoe.c -lwinmm
```

To run the game:

```bash
tictactoe.exe
```
