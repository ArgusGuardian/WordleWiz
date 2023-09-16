# Wordwiz Game Readme

## Introduction

Wordwiz is a word-guessing game inspired by the popular game Wordle. In Wordwiz, your objective is to guess the "word of the day" within a limited number of tries. The game challenges your word-guessing skills and vocabulary. It's a fun and engaging way to test your knowledge of words!

## Gameplay

- When you start the game, you'll be presented with the "word of the day," which is a secret word that you need to guess.
- You have a limited number of tries to guess the word correctly (the number of tries is specified in the game).
- You can guess the word by entering a word of the same length as the secret word.
- If you guess a letter in the correct position, it will be revealed in the word.
- If you guess a letter incorrectly or it's not in the word, it won't be revealed, and you'll receive feedback.
- The length of the secret word will be represented by underscores, and correct guesses will replace the underscores with the correct letters.
- The game will display the number of tries you have left, so use them wisely!

## How to Play

1. Start the game, and you'll receive the "word of the day."
2. Enter your guess, which should be a word of the same length as the secret word.
3. If your guess is incorrect, the game will provide feedback and show your progress.
4. Keep guessing until you correctly guess the word or run out of tries.

## Building and Running the Game

To build and run the Wordwiz game, you need to compile the provided source code with a C compiler. Here are the steps:

1. Compile the code using a C compiler. For example, if you have GCC installed, you can use the following command:

   ```shell
   gcc main.c -o wordwiz
   ```

2. Run the game:

   ```shell
   ./wordwiz
   ```

## Customization

You can customize the game by modifying the `DB.txt` file, which contains the list of words that can be selected as the "word of the day." Add or remove words to change the words that players can guess.

## Acknowledgments

This game is a simple implementation inspired by the Wordle game. It was created for educational and entertainment purposes.

## Author

Wordwiz was developed by Alaa Eddine.

Enjoy playing Wordwiz and have fun guessing words!
