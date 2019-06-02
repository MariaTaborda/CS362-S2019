#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>



int main (){
	struct gameState state ;
	int numberofPlayers = 2; //Using this to make comparison easier
	int k[10] = {adventurer, council_room, cutpurse, gardens, great_hall,
		outpost, sea_hag, smithy, tribute, village}; //random set for supplies
	int numaction1 =0;
	int numaction2 =0;
	int handcount1 =0; 
	int handcount2 =0;

	printf ("VILLAGE TEST\n");	
	initializeGame(numberofPlayers, k, 2000, &state); // this will save the original state of the game after being initialized
	printf ("Game succesfully initialized\n");
	state.hand[0][state.handCount[0]] = 6;
	state.handCount[0]++;
	buyCard(14, &state); // Adding this to test if I can actually buy the card
	
	numaction1 = state.numActions;
	//printf ("Number of actions before playing village =  %d\n", numaction1); 
	handcount1 = state.handCount[0];
	//printf ("Number of cards in hand before playing village =  %d\n", handcount1); 

	cardEffect (village, 0, 0, 0, &state, 0, 0);
	numaction2 = state.numActions;
	//printf ("Number of actions after playing village =  %d\n", numaction2); 
	handcount2 = state.handCount[0];
	//printf ("Number of cards after playing village =  %d\n", handcount2); 
	
	if (handcount2 == handcount1){
	printf ("Test 1 Passed, current player added a card to their hand \n");
	}
	else
	printf ("Test 1 failed, Village didn't add the correct amount of cards to player's hand \n");

	if (numaction2 == numaction1+2){
	printf ("Test 1 Passed, current player has 2 additional actions available \n");
	}
	else
	printf ("Test 1 failed, Village didn't add the correct amount actions to player \n");	


	return 0;
}
