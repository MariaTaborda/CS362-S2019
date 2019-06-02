#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


int main (){
	srand (time(NULL));
	struct gameState state ;
	int numberofPlayers = 2; //Using this to make comparison easier
	int k[10] = {adventurer, council_room, cutpurse, gardens, great_hall,
		outpost, sea_hag, smithy, tribute, village}; //random set for supplies
	int possibleCards[17] = {4, 1, 2, 3, 0, 5, 6, 7, 8, 21, 10, 16, 23, 25, 13, 19, 14};

	int handcountp1b =0; 
	int handcountp2b =0;
	int handcountp1a =0;
	int handcountp2a = 0;
	int numBuys1 =0;
	int numBuys2=0;
	int failtest = 0;
	int passtest =0;
	
	
	printf ("COUNCIL ROOM TEST\n");
	initializeGame(numberofPlayers, k, 2000, &state); // this will save the original state of the game after being initialized
	printf ("Game Succesfully initialized\n");
	printf ("Randomizing GAME STATE Variables\n");
	
	for (int count = 0; count < 1000; count++){
		state.deckCount[0] = rand() % 50;
		//printf ("State Deck Count = %d\n", state.deckCount[0]);
		state.handCount[0] = rand() % 5;
		state.handCount[1] = rand() % 5;
		   for (int j =0; j<state.handCount[0]; j++){
			state.hand[0][j] = possibleCards [(rand() %17)];
			//printf ("State Hand Player %d Position %d = %d\n", i, j, state.hand[i][j]);	
		}	
		 for (int j =0; j<state.handCount[1]; j++) {
		state.hand[1][j] = possibleCards [(rand() %17)];
		}
		


	numBuys1 = state.numBuys;
	//printf ("Number of buys before playing council_room =  %d\n", numBuys1); 
	handcountp1b = state.handCount[0];
	handcountp2b = state.handCount[1];
	//printf ("Number of cards in p1 hand before playing council_room =  %d\n", handcountp1b); 
	//printf ("Number of cards in p2 hand before playing council_room =  %d\n", handcountp2b); 


	cardEffect (council_room, 0, 0, 0, &state, 0, 0);
	numBuys2 = state.numBuys;
	//printf ("Number of buys after playing council_Room =  %d\n", numBuys2); 
	handcountp1a = state.handCount[0];
	handcountp2a =state.handCount[1];
	//printf ("Number of cards in p1 after playing council_Room =  %d\n", handcountp1a); 
	//printf ("Number of cards in p2 hand after playing council_room =  %d\n", handcountp2a); 
	

	if (handcountp1a == handcountp1b+3){
	//printf ("Test 1 Passed, current player has 3 additional cards on their hand, after discarding Council Room \n");
	passtest++;
	}
	else{
	printf ("Test 1 failed, Council Room didn't add the correct amount of cards to player's hand \n");
	failtest++;
	}

	if (numBuys2 == numBuys1+1){
	//printf ("Test 2 Passed, current player has 1 additional buy available, after playing Council Room \n");
	passtest++;
	}
	else{
	printf ("Test 2 failed, the number of buys doesn't match the expected after playing Council Room \n");
	failtest++;
	}

	if (handcountp2a == handcountp2b+1){
	//printf ("Test 3 passed, the number of cards in player 2 hand matches the expected after playing Council Room \n");
	passtest++;
	}
	else {
	printf ("Test 3 failed, the number of cards in player 2 hand doesn't match the expected after playing Council Room \n");
	failtest++;

	}

	
	
	// emptyDeck for boundary check
//	for (int i = 0; i<state.deckCount[0];){ 
//drawCard (0, &state);
//	discardCard (0,0,&state,0);
	//printf ("Discard card Count %d\n", state.discardCount[0]);		
	//printf ("Deck Count %d\n", state.deckCount[0]);
	//printf ("Played Cards count %d\n", state.playedCardCount); 
	}

	//handcountp1b =state.handCount[0];
	//printf ("%d cards on hand before\n", handcount1);
//	cardEffect (council_room, 0, 0, 0, &state, 0, 0);	
//	handcountp1a = state.handCount[0];
	//printf ("%d cards on hand after\n", handcount2);
//	if (handcountp1a == handcountp1b+2){
	//printf ("Test 4 Passed, correct handling of empty deck \n");
//	passtest++;
//	}
//	else{
//	printf ("Test 4 failed, empty deck test case was not correctly handled \n");
//	failtest++;
//	}
//	}

	printf ("Run 3000 tests, %d passed and %d failed\n", passtest, failtest);
	return 0;
}
