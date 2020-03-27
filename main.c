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
 * 	>	User interaction.
 * 	>	Track cards played for all rounds.
 * 	>	Track who won each round.
 * 	>	Declare an overall winner.
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
#define PLAYERS 4
#define NUM_OF_CARDS 5
#define ROUNDS 4

// Prototypes
void dealACard(char *suits[], char *faces[], int deck[][FACES]);
void dealARound(char **suits, char **faces, int ***playerHands, int round);
void dealAHand(char **suits, char **faces, int deck[][FACES], int
***playerHands, int player, int round);
void dealAGame(char *suits[], char *faces[], int playerHands[][PLAYERS][NUM_OF_CARDS]);
void printHands(int hands[][SUITS][FACES]);
void tester(char *suits[], char *faces[], int deck[][FACES], int
playerHands[][PLAYERS][NUM_OF_CARDS], int player, int card, int round);

/*
 * Name:			main()
 * Parameters:		None.
 * Processes:		FIXME
 * Return Value:	An integer representing an error code; if the program ends without error,
 * 					zero will be returned to the calling program or operating system.
 */
int main() {

	// Variables
	char *suits[SUITS] = {"Hearts", "Diamonds", "Spades", "Clubs"};
	char *faces[FACES] = {"Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten",
					   "Jack", "Queen", "King", "Ace"};
	// int deck[SUITS][FACES] = {AVAILABLE};
	int playerHands[ROUNDS][PLAYERS][NUM_OF_CARDS] = {AVAILABLE};

	// Calculation
	srand(time(NULL));
	dealAGame(suits, faces, playerHands);

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
		suitIndex = rand() % SUITS;
		faceIndex = rand() % FACES;
	} while (deck[suitIndex][faceIndex] == TAKEN);

	deck[suitIndex][faceIndex] = TAKEN;

	// Output
	// printf("%s of %s\n", faces[faceIndex], suits[suitIndex]);

} // end dealACard

/*
 * Name:			dealARound()
 * Parameters:		*suits[]		An array of card suits.
 * 					*faces[]		An array of card face values.
 * 					deck[][FACES]	An array of array for each suit and face to track cards played.
 * Processes:		Deal a 5 card draw poker hand of cards;	Absolute: 5 cards dealt.
 * Return Value:	None.
 */
void dealARound(char **suits, char **faces, int ***playerHands, int round) {

	int deck[SUITS][FACES] = {AVAILABLE};

	for (int player = 0; player < PLAYERS; player++) {
		dealAHand(suits, faces, deck, playerHands, player, round);
	}

	printf("\n\n\n----- NEW ROUND -----\n\n\n");

} // end dealARound

/*
 * Name:			dealAHand()
 * Parameters:		*suits[]		An array of card suits.
 * 					*faces[]		An array of card face values.
 * 					deck[][FACES]	An array of array for each suit and face to track cards played.
 * Processes:		Deal a 5 card draw poker hand of cards;	Absolute: 5 cards dealt.
 * Return Value:	None.
 */
void dealAHand(char **suits, char **faces, int deck[][FACES], int
***playerHands, int player, int round) {

	// Calculation
	for (int card = 0; card < NUM_OF_CARDS; card++) {
		// dealACard(suits, faces, deck);
		tester(suits, faces, deck, playerHands, player, card, round);
	}

	// FIXME: delete when done
	printf("\n=====\n\n");

} // end dealAHand

/*
 * Name:			FIXME()
 * Parameters:		None.
 * Processes:		FIXME
 * Return Value:	FIXME
 */
void dealAGame(char *suits[], char *faces[], int
playerHands[][PLAYERS][NUM_OF_CARDS]) {
	for (int round = 0; round < ROUNDS; round++) {
		dealARound(suits, faces, (int ***) playerHands, round);
	}
} // end dealAGame

/*
 * Name:			FIXME()
 * Parameters:		None.
 * Processes:		FIXME
 * Return Value:	FIXME
 */
void printHands(int hands[][SUITS][FACES]) {}

/*
 * Name:			tester()
 * Parameters:		Varying.
 * Processes:		Test functionality without changing main functions. Copy / paste to
 * 					appropriate function body once it works.
 * Return Value:	None.
 */
void tester(char *suits[], char *faces[], int deck[][FACES], int
playerHands[][PLAYERS][NUM_OF_CARDS], int player, int card, int round) {

	// Variables
	int suitIndex = 0,
		faceIndex = 0;

	// Calculation
	do {
		suitIndex = rand() % SUITS;
		faceIndex = rand() % FACES;
	} while (deck[suitIndex][faceIndex] == TAKEN);

	deck[suitIndex][faceIndex] = TAKEN;
	playerHands[round][player][card] = suitIndex * 100 + faceIndex;

	// Output
	printf("%s of %s\n", faces[faceIndex], suits[suitIndex]);

}