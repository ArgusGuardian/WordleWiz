#ifndef MAIN_H
#define MAIN_H

// LIBRARIES
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// GLOBAL VARIABLES
#define rounds 6

// STRUCTURES
typedef struct word
{
	int word_id;
	char *word;
} word;

// FUNCTIONS
int generate_id();
char *select_word(int generated_id);
int word_len(char *word);
char *place_holder(char *word, char *guessed_word);
void check_rounds(char *word);
#endif