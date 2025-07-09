Multi-Mode Tic-Tac-Toe
Overview
This is a console-based Tic-Tac-Toe game in C designed for Windows terminals. It supports:

2-player classic mode

AI mode (Player vs Computer)

3-player mode (4x4 board)

Scoreboard tracking with file I/O
It uses gotoxy, Beep, and system("cls") for interactive console behavior.

Game Modes
1. Classic 2-Player Mode
Board: 3x3

Players: Choose between X and O

Win Condition: 3 in a row (row/column/diagonal)

Post-Game: Winner plays against AI

2. AI Mode
Board: 3x3

Player vs AI

AI Logic:

First tries to win

Then tries to block player

Else plays a random move

Now uses recursive logic instead of loops for smarter move selection

Results are saved in scoreboard.txt

3. 3-Player Mode (Extended)
Board: 4x4 grid

Players: Symbols X, Y, and Z

Win Condition: 4 in a row (horizontal/vertical/diagonal)

Results saved with player number and name

Features
 Scoreboard Logging
Uses scoreboard.txt to store game outcomes

Tracks:

Winner and loser in AI mode

Winning player in 3-player mode

🎮 Interactive Terminal UI
Cursor movement using gotoxy

Screen cleared after each move

Beep sounds in loading animation for feedback

 AI Uses Recursion
aiMove() function rewritten to use recursive logic

Smarter AI that checks for:

Winning opportunity

Blocking opponent

Picking a random empty spot

 Input Validation
No overwriting allowed

Symbols must be valid

Input range is validated in all modes

 Extras
load() function with beep-based animated loader

Color changes using system("COLOR Fx") for game states
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

