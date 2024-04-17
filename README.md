# Resizable Tic Tac Toe Game in C

This repository contains a resizable tic-tac-toe game implemented in C. The game allows players to specify the dimensions of the board and dynamically resizes it accordingly. It includes error checking for invalid inputs, detection of a winning condition, and a tie scenario. The game alternates between two players ('X' and 'O') until a winner is determined or the game ends in a tie.

## How to Play
1. Clone this repository to your local machine.
2. Compile the code using a C compiler (e.g., GCC).
    ```bash
    gcc main.c -o tic_tac_toe
    ```
3. Run the compiled executable.
    ```bash
    ./tic_tac_toe
    ```
4. Follow the prompts to specify the dimensions of the board and make your moves.

## Features
- Resizable board: Players can choose the dimensions of the board.
- Error checking: Validates user inputs to prevent illegal moves.
- Winning condition: Detects when a player achieves victory.
- Tie scenario: Ends the game in a tie if no player wins.
