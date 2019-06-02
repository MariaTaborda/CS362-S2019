#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>



int main (){
	struct gameState state, test1 ;
	int numberofPlayers = 2; //Using this to make comparison easier
	int k[10] = {adventurer, council_room, cutpurse, gardens, great_hall,
		outpost, sea_hag, smithy, tribute, village}; //random set for supplies
	int numaction1 =0;
	int numaction2 =0;
	int handcount1 =0; 
	int handcount2 =0;
	int score1 =0;
	int score2=0;
			
	initializeGame(numberofPlayers, k, 2000, &state); // this will save the original state of the game after being initialized
	printf ("Game initialized\n");
	
	memcpy (&test1, &state, sizeof(struct gameState)); // copy the initialized game into a test struct to run unit test
	score1= scoreFor(0, &state);
	printf ("Score before adding great_hall to player's hand = %d\n", score1);
	state.hand[0][state.handCount[0]] = 16;
	state.handCount[0]++;
	score2= scoreFor(0, &state);
	printf ("Score after adding great_hall to player's hand = %d\n", score2);
	
	numaction1 = state.numActions;
	printf ("Number of actions before playing great_hall =  %d\n", numaction1); 
	handcount1 = state.handCount[0];
	printf ("Number of cards in hand before playing great_hall =  %d\n", handcount1); 
	

	cardEffect (great_hall, 0, 0, 0, &state, 0, 0);
		numaction2 = state.numActions;
	printf ("Number of actions after playing great_hall =  %d\n", numaction2); 
		handcount2 = state.handCount[0];
	printf ("Number of cards after playing great_hall =  %d\n", handcount2); 
	
	/*for (int i; i<state.handCount[0]; i++){
	printf ("card %d = %d \n", i, state.hand[0][i]);
	}
	


	if (treassurecount2 == treassurecount1+2){
	printf ("Test Passed, current player has 2 additional trassure cards on their hand");
	}
	else
	printf ("Test failed, Adventurer cards didn't add the correct amount of trassures to player's hand");
	*/
	return 0;
}
