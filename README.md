# Chicago

A command-line dice game written in C where you play against the computer.
Two dice are rolled each turn, and the goal is to hit the round's target number.

## How to Play
1. At the start, both sides roll two dice. The higher total plays first
   (a tie means rolling again).
2. Choose how many rounds to play (1-11).
3. In round *n*, the target is *n + 1*. On each turn, two dice are rolled,
   and if their sum equals the target, you score that many points.
4. Each side gets up to 3 turns per round.
5. Scores are shown after every round, and the player with the highest
   total at the end wins.

### Special Rules
- **Player:** After the first and second turns, you can choose to roll
  again (Y/N). If you chose to roll again and then miss the target,
  your score for that round resets to 0.
- **Computer:** If the dice sum is exactly one below the target, the
  computer rolls again (up to 3 turns).

## Features
- Random dice rolls with `rand()` seeded by `time()`
- Turn order decided by an initial dice roll
- Input validation for the number of rounds
- Round-by-round scoresheet and final winner announcement

## Concepts Used
- Functions and modular program structure
- Loops and conditionals
- Random number generation (`rand`, `srand`)
- User input handling with `scanf`

## Build and Run
    gcc main.c -o chicago
    ./chicago

## Example
    Welcome to Chicago game.
    Let's get started!

    How many rounds would you like to play?3

    Round 1 -- Your Turn: (Target = 2)
    ==================================================
    you got > [Dice 1]: 1 [Dice 2]: 1
    Your score: 2 Total score: 2
