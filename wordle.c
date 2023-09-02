#include "main.h"

int main(void)
{
	word *word_of_day;
	word_of_day->word = malloc(50);
	char guessed_word[50];

	printf("\n\t\t\tWELCOME TO WORDLE!\n\n");
	printf("Your objective is to guess the word of the day in under %d tries!\n\n", rounds);
	printf("Things to know: \n");
	printf("- if you guess the right letter in the correct place the letter will be shown!\n");
	printf("- if you guess the letter wrong it wont't be shown!\n");
	printf("- the word lenght will be represented by the number of _ shown.\n");
	putchar('\n');

	word_of_day->word_id = generate_id();
	word_of_day->word = select_word(word_of_day->word_id);
	check_rounds(word_of_day->word);

	free(word_of_day->word);
	return 0;
}

// GENERATE RANDOM ID
int generate_id()
{
	int id;
	srand(time(NULL));
	id = rand() % 101; // GENERATE RANDOM ID [0 - 100]
	return (id);
}

// MATCH THE ID GENERATED TO ID OF THE WORD IN DB
char *select_word(int generated_id)
{
	static char word[50];
	int id;

	FILE *file;
	file = fopen("DB.txt", "r");
	if (file == NULL)
	{
		perror("Error opening the file");
		exit(1);
	}
	do
	{
		if (fscanf(file, "%d%s", &id, word) != 2)
		{
			fprintf(stderr, "Error reading from the file\n");
			fclose(file);
			exit(1);
		}
	} while (id != generated_id);
	// printf("(%s)", word); // TOGGLE TO SHOW WORD SLECTED
	fclose(file);

	return (word);
}

// CHECK THE LENGHT OF THE WORD FROM DB
int word_len(char *word)
{
	int i = 0;

	while (word[i] != '\0')
		i++;
	return (i);
}

// GENERATE PLACEHOLDER FOR THE WORD (MATCH WITH GUESSES)
char *place_holder(char *word, char *guessed_word)
{
	int i = 0;
	static char to_print[50];

	while (word[i] != '\0')
	{
		if (word[i] == guessed_word[i])
			to_print[i] = word[i];
		else
			to_print[i] = '_';
		i++;
	}
	to_print[i] = '\0';
	return (to_print);
}

// MANAGE ROUNDS
void check_rounds(char *word)
{
	char guessed_word[50];
	int count = 0, len;
	char *placeholder;

	len = word_len(word);

	for (int i = 0; i < len; i++)
		printf("_ ");
	putchar('\n');
	do
	{
		printf("\nEnter your guess: ");
		scanf("%s", guessed_word);
		if (strcmp(word, guessed_word) != 0)
		{
			placeholder = place_holder(word, guessed_word);
			printf("\nWrong answer!\n\n");
			for (int j = 0; placeholder[j] != '\0'; j++)
			{
				putchar(placeholder[j]);
				putchar(' ');
			}
			count++;

			printf("\t\t Tries left %d/6\n", (rounds - count));
		}
		else
		{
			printf("congats the word of the day is %s", word);
			break;
		}
	} while (count < rounds);
}
