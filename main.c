/*
 * File Name:		cardGame.c
 * Name:			Joshua Andujar
 * Course:			COP 2220C at Valencia College
 * Facilitator:		David Stendel
 * Description:		FIXME
 * Team Members:	None.
 * Date:			3/27/20
 */

// =================================================================================================

/*
 * Name:			FIXME()
 * Parameters:		None.
 * Processes:		FIXME
 * Return Value:	FIXME
 */

// =================================================================================================

/*
 * =================================================================================================
 * SPECIFICATION:
 * 	>	Generate a number within a range.
 * 	>	Generate a random number from 0 - 3, and a number from 0 - 12. Use these random numbers
 * 		to output a card. Eg: "King of Clubs"
 * 	>	Deal a hand of 5 cards.
 * 	>	Deal 4 hands of cards.
 * =================================================================================================
 */

// Preprocessor Directives
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Macros
#define SUITS 4
#define FACES 13
#define AVAILABLE 0
#define TAKEN 1

// Prototypes
void dealACard(char *suits[], char *faces[], int deck[][FACES]);
void dealAGame(char **suits, char **faces, int **deck);

/*
 * Name:			main()
 * Parameters:		None.
 * Processes:		FIXME
 * Return Value:	An integer representing an error code; if the program ends without error,
 * 					zero will be returned to the calling program or operating system.
 */
int main() {

	// Variables
	char *suits[4] = {"Hearts", "Diamonds", "Spades", "Clubs"};
	char *faces[13] = {"Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten",
					"Jack", "Queen", "King", "Ace"};
	int deck[4][13] = {AVAILABLE};

	// Calculation
	srand(time(NULL));
	for (int i = 0; i < 10; ++i) {
		dealAGame(suits, faces, deck);
		printf("\n=============================\n\n");
	}

    // Output
    return 0;

} // end main

/*
 * Name:			dealACard()
 * Parameters:		*suits[]		An array of card suits.
 * 					*faces[]		An array of card face values.
 * 					deck[][FACES]	An array of array for each suit and face to track cards played.
 * Processes:		Randomly choose a suit and a face to choose a card to deal.
 * Return Value:	None.
 */
void dealACard(char *suits[], char *faces[], int deck[][FACES]) {

	// Variables
	int suitIndex = 0,
		faceIndex = 0;

	// Calculation
	do {
		suitIndex = rand() % 4;
		faceIndex = rand() % 13;
	} while (deck[suitIndex][faceIndex] == TAKEN);

	deck[suitIndex][faceIndex] = TAKEN;

	// Output
	printf("%s of %s\n", faces[faceIndex], suits[suitIndex]);

} // end dealACard

/*
 * Name:			dealAGame()
 * Parameters:		*suits[]		An array of card suits.
 * 					*faces[]		An array of card face values.
 * 					deck[][FACES]	An array of array for each suit and face to track cards played.
 * Processes:		Deal a 5 card draw poker hand of cards;	Absolute: 5 cards dealt.
 * Return Value:	None.
 */
void dealAGame(char **suits, char **faces, int **deck) {

	for (int index = 0; index < 4; index++) {
		dealACard(suits, faces, deck);
	}

} // end dealAGame