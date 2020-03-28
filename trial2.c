/*
 * File Name:		cardGame.c
 * Name:			Joshua Andujar
 * Course:			COP 2220C at Valencia College
 * Facilitator:		David Stendel
 * Description:		Five card draw poker game.
 * Team Members:	None.
 * Date:			3/27/20
 */

/*
 * Name:			FIXME()
 * Parameters:		None.
 * Processes:		FIXME
 * Return Value:	FIXME
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
void dealACard(char *suits[], char *faces[], int deck[][FACES], int
playerHands[][PLAYERS][NUM_OF_CARDS], int player, int card, int round);
void dealARound(char **suits, char **faces, int playerHands[][PLAYERS][NUM_OF_CARDS], int round);
void dealAHand(char **suits, char **faces, int deck[][FACES], int
playerHands[][PLAYERS][NUM_OF_CARDS], int player, int round);
void dealAGame(char *suits[], char *faces[], int playerHands[][PLAYERS][NUM_OF_CARDS], int
roundWinners[]);
void printStats(int hands[][SUITS][NUM_OF_CARDS], int results[]);
void determineRoundWinner(int playerHands[][PLAYERS][NUM_OF_CARDS], int round, int *roundWinners);

/*
 * Name:			main()
 * Parameters:		None.
 * Processes:		Play a game of Five Card Draw, print the hands for each round, the winners of
 * 					each round and the overall game winner.
 * Return Value:	An integer representing an error code; if the program ends without error,
 * 					zero will be returned to the calling program or operating system.
 */
int main() {

	// Variables
	char *suits[SUITS] = {"Hearts", "Diamonds", "Spades", "Clubs"};
	char *faces[FACES] = {"Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten",
						  "Jack", "Queen", "King", "Ace"};
	// int deck[SUITS][FACES] = {AVAILABLE};
	int playerHands[ROUNDS][PLAYERS][NUM_OF_CARDS] = {AVAILABLE},
		roundWinners[ROUNDS] = {AVAILABLE};

	// Calculation
	srand(time(NULL));
	dealAGame(suits, faces, playerHands, roundWinners);

	// Output
	printStats(playerHands, roundWinners);
	return 0;

} // end main

/*
 * Name:			dealACard()
 * Parameters:		*suits[]			An array of card suits.
 * 					*faces[]			An array of card face values.
 * 					deck[][]			An array of array for each suit and face to track cards played.
 * 					playerHands[][][]	The array keeping track of each players hand for each
 * 										round.
 * 					player				The current player receiving cards.
 * 					card				The card number being dealt to the current player.
 * 					round				The round that cards are being dealt for.
 * Processes:		Randomly choose a suit and a face to choose a card to deal, then deal it to a
 * 					player.
 * Return Value:	None.
 */
void dealACard(char *suits[], char *faces[], int deck[][FACES], int
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

} // end dealACard

/*
 * Name:			dealARound()
 * Parameters:		**suits				An array of card suits.
 * 					**faces				An array of card face values.
 * 					playerHands[][][]	The array keeping track of each players hand for each
 * 										round.
 * 					round				The round that cards are being dealt for.
 * Processes:		Deal a hand of Five Card Draw to each player.
 * Return Value:	None.
 */
void dealARound(char **suits, char **faces, int playerHands[][PLAYERS][NUM_OF_CARDS], int round) {

	// Variables
	int deck[SUITS][FACES] = {AVAILABLE};

	// Calculation
	for (int player = 0; player < PLAYERS; player++) {
		dealAHand(suits, faces, deck, playerHands, player, round);
	}

} // end dealARound

/*
 * Name:			dealAHand()
 * Parameters:		**suits				An array of card suits.
 * 					**faces				An array of card face values.
 * 					deck[][]			An array of array for each suit and face to track cards
 * 										played.
 * 					playerHands[][][]	The array keeping track of each players hand for each
 * 										round.
 * 					player				The current player receiving cards.
 * 					round				The round that cards are being dealt for.
 * Processes:		Deal a five card hand of Five Card Draw.
 * Return Value:	None.
 */
void dealAHand(char **suits, char **faces, int deck[][FACES], int
playerHands[][PLAYERS][NUM_OF_CARDS], int player, int round) {

	// Calculation
	for (int card = 0; card < NUM_OF_CARDS; card++) {
		dealACard(suits, faces, deck, playerHands, player, card, round);
	}

} // end dealAHand

/*
 * Name:			dealAGame()
 * Parameters:		*suits[]			An array of card suits.
 * 					*faces[]			An array of card face values.
 * 					playerHands[][][]	The array keeping track of each players hand for each
 * 										round.
 * 					roundWinners[]		The array where the index of winner is stored at the
 * 										index for that round.
 * Processes:		Deal four rounds of Five Card Draw and then determine the winners of each round.
 * Return Value:	None.
 */
void dealAGame(char *suits[], char *faces[], int
playerHands[][PLAYERS][NUM_OF_CARDS], int roundWinners[]) {

	// Calculation
	for (int round = 0; round < ROUNDS; round++) {
		dealARound(suits, faces, playerHands, round);
		determineRoundWinner(playerHands, round, roundWinners);
	}

} // end dealAGame

/*
 * Name:			printStats()
 * Parameters:		hands[][][]			The array keeping track of each players hand for each
 * 										round.
 * 					results[]			The array where the index of winner is stored at the
 * 										index for that round.
 * Processes:		Print each players hand, for each round and then print the winners of each
 * 					round.
 * Return Value:	None.
 */
void printStats(int hands[][SUITS][NUM_OF_CARDS], int results[]) {

	for (int round = 0; round < ROUNDS; ++round) {
		printf("\n=====     Round %i     =====\n", round + 1);
		for (int player = 0; player < PLAYERS; ++player) {
			printf("\tPlayer %i Hand\n", player + 1);
			for (int card = 0; card < NUM_OF_CARDS; ++card) {
				printf("\t\tCard %i: %i\n", card + 1, hands[round][player][card]);
			}
		}
		printf("\n\tRound %i Winner: Player %i\n", round + 1, results[round] + 1);
	}

	// printf("%s of %s\n", faces[faceIndex], suits[suitIndex]);

}

/*
 * Name:			determineRoundWinner()
 * Parameters:		playerHands[][][]	The array keeping track of each players hand for each
 * 										round.
 * 					round				The round number to determine a winner for.
 * 					*roundWinners		The array where the index of winner is stored at the
 * 										index for that round.
 * Processes:		Test each players hand for a round, tracking whose is best to determine the
 * 					round winner.
 * Return Value:	None.
 */
void determineRoundWinner(int playerHands[][PLAYERS][NUM_OF_CARDS], int round, int *roundWinners) {

	// Function Variables
	int winnerIndex = 0,
		winningHandWorth = 0,
		roundHighCardPlayer = 0,
		roundHighCard = 0,
		roundHighPair = 0,
		roundHighPairPlayer = 0,
		roundHighToK = 0,
		roundHighToKPlayer = 0,
		roundHighFoK = 0,
		roundHighFoKPlayer = 0;

	// Calculation: Test each player's hand.
	for (int player = 0;  player < PLAYERS; player++) {

		// Player Variables
		int handWorth = 0;
		int suits[SUITS] = {AVAILABLE},
			faces[FACES] = {AVAILABLE};

		// Look at players hand and determine suits and faces.
		for (int card = 0; card < NUM_OF_CARDS; card++) {
			int currentCard = playerHands[round][player][card];
			suits[currentCard / 100] += 1;
			faces[currentCard % 100] += 1;
		} // end inner for

		// Check for a Flush. Start here because if is the simplest to check for.
		for (int suit = 0; suit < SUITS; suit++) {
			if (suits[suit] == 5) {

				// Check for a Straight / Royal Flush
				for (int face = 0; face < FACES; face++) {
					if (faces[face] == 1) {
						if (faces[face + 1] == 1) {
							if (faces[face + 2] == 1) {
								if (faces[face + 3] == 1) {
									/*
									 * While checking for a straight we have to remember that a
									 * straight can start with an ace which is our index 12 in
									 * this scenario. Check if trigger index is two and Ace is 1.
									 */
									if (faces[face + 4] == 1 || (faces[12] == 1 && face == 0)) {
										if (face == 8) {
											handWorth = 10;
										}
										else {
											handWorth = 9;
										}
									}
								}
							}
							/*
							 * Put the fail condition to a straight on the second else. We will
							 * find a face with a 1, the real test for a straight is if the
							 * subsequent face is also a 1. If it is not then there is no
							 * straight and we can proceed to assigning points for a flush.
							 */
						} else {
							handWorth = 6;
						}
					}

				} // end straight / royal flush for

			} // end flush if
		} // end flush for

		// Check for Four of a Kind, Three of a Kind and Pairs.
		if (handWorth == 0) {

			// Variables
			int threeOfAKind = 0,
				pair = 0,
				highestCard = 0;

			/*
			 * While checking for Four of a Kind, etc. also check to see if their hand has higher
			 * precedence that any other equal hand.
			 */
			for (int face = 0; face < FACES; face++) {
				if (faces[face] == 4) {
					// If you have a Four of a Kind you don't have anything else, assign points.
					handWorth = 8;
					if (face > roundHighFoK) {
						roundHighFoK = face;
						roundHighFoKPlayer = player;
					}
				} else if (faces[face] == 3) {
					// If you have a Three of a Kind we still need to check for a pair. (Full House)
					threeOfAKind += 1;
					if (face > roundHighToK) {
						roundHighToK = face;
						roundHighToKPlayer = player;
					}
				} else if (faces[face] == 2) {
					// If you have a Pair we still need to check for another pair. (Two Pair)
					pair += 1;
					if (face > roundHighPair) {
						roundHighPair = face;
						roundHighPairPlayer = player;
					}
				}

				// Tracking High Card for round and who had it.
				if (faces[face] >= 1 && face > highestCard) {
					highestCard = face;
					if (highestCard > roundHighCard) {
						roundHighCardPlayer = player;
						roundHighCard = highestCard;
					}
				}
			} // end FoK / ToK / Pair for

			// Decide if hand is Full House, Three of a Kind, Two Pair or Pair.
			if (threeOfAKind == 1 && pair == 1) {
				// Full House check.
				handWorth = 7;
			} else if (threeOfAKind == 1 && pair == 0) {
				// Three of a Kind check if other checks fail.
				handWorth = 4;
			} else if (pair == 2) {
				// Two Pair check if other checks fail.
				handWorth = 3;
			} else if (pair == 1) {
				// Pair check if other checks fail.
				handWorth = 2;
			}

		} // end FoK / ToK / Pair check

		// Check for a Straight.
		if (handWorth == 0) {

			for (int face = 0; face < FACES; face++) {
				if (faces[face] == 1) {
					if (faces[face + 1] == 1) {
						if (faces[face + 2] == 1) {
							if (faces[face + 3] == 1) {
								if (faces[face + 4] == 1 || (faces[12] == 1 && face == 0)) {
									handWorth = 5;
								}
							}
						}
					}
				}
			} // end Straight for

		} // end Straight Check

		// If nothing else was triggered, assign a point to handWorth for High Card.
		if (handWorth == 0) {
			handWorth = 1;
		}

		// Check if current player's hand worth beats the current winning hand and act accordingly.
		if (handWorth > winningHandWorth) {
			// If the handWorth beats the currently winning handWorth, replace it and the player.
			winningHandWorth = handWorth;
			winnerIndex = player;
		} else if (handWorth == winningHandWorth) {
			// If a tie is found, determine whose hand has higher precedence.
			switch (handWorth) {
				case 8:
					if (roundHighFoKPlayer != winnerIndex) {
						winnerIndex = roundHighFoKPlayer;
					}
					break;
				case 4:
					if (roundHighToKPlayer != winnerIndex) {
						winnerIndex = roundHighToKPlayer;
					}
					break;
				case 3:
				case 2:
					if (roundHighPairPlayer != winnerIndex) {
						winnerIndex = roundHighPairPlayer;
					}
					break;
				case 1:
					if (roundHighCardPlayer == player) {
						winnerIndex = player;
					}
			}
		}

	} // end outer for

	roundWinners[round] = winnerIndex;

} // end determineRoundWinner