#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int main (){
	struct gameState state;
	int numberofPlayers = 2; //Using this to make comparison easier
	int k[10] = {adventurer, council_room, cutpurse, gardens, great_hall,
		outpost, sea_hag, smithy, tribute, village}; //random set for supplies
	int handcount1 = 0;
	int handcount2 = 0;
	printf ("SMITHY TEST \n");			
	initializeGame(numberofPlayers, k, 2000, &state); // this will save the original state of the game after being initialized
	printf ("Succesfully initialized game\n");

	//cardEffect (smithy, 0, 0, 0, &state, 0,0);
	//printf ("Discard card Count %d\n", state.discardCount[0]);		
	handcount1 =state.handCount[0];
	cardEffect (smithy, 0, 0, 0, &state, 0, 0);
	handcount2 = state.handCount[0];
	//printf ("Discard card Count %d\n", state.discardCount[0]);		

	if (handcount2 == handcount1+2){
	printf ("Test 1 Passed, current player has 2 additional cards on their hand, after discarding smithy \n");
	}
	else
	printf ("Test 1 failed, Smithy didn't add the correct amount of cards to player's hand \n");
	
	// empty the deck to evaluate the if condition for the drawCard function
	for (int i = 0; i<state.deckCount[0];){ 
	drawCard (0, &state);
	discardCard (0,0,&state,0);
	//printf ("Discard card Count %d\n", state.discardCount[0]);		
	//printf ("Deck Count %d\n", state.deckCount[0]);
	//printf ("Played Cards count %d\n", state.playedCardCount); 
	}

	handcount1 =state.handCount[0];
	//printf ("%d cards on hand before\n", handcount1);
	cardEffect (smithy, 0, 0, 0, &state, 0, 0);	
	handcount2 = state.handCount[0];
	//printf ("%d cards on hand after\n", handcount2);

	if (handcount2 == handcount1+2){
	printf ("Test 2 Passed, correct handling of empty deck \n");
	}
	else
	printf ("Test 2 failed, empty deck test case was not correctly handled \n");
	
	return 0;
}
