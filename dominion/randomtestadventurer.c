#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int treassureCount (struct gameState s, int player){
	int count = 0;
	for (int i =0; i<s.handCount[player]; i++){
	if (s.hand[player][i] == 4 || s.hand[player][i] ==5 || s.hand[player][i] == 6 ){
	count++;
	}
	//printf ("Count %d \n", count);
	} 
	return count; 
	
}

int main (){
	struct gameState state;
	int numberofPlayers = 2; //Using this to make comparison easier
//	int init;
	int k[10] = {adventurer, council_room, cutpurse, gardens, great_hall,
		outpost, sea_hag, smithy, tribute, village}; //random set for supplies
	int possibleCards[17] = {4, 1, 2, 3, 0, 5, 6, 7, 8, 21, 10, 16, 23, 25, 13, 19, 14};
	int treassurecount1 =0;
	int treassurecount2 =0;
	int handCount1 =0;
	int handCount2 =0;
	srand (time(NULL));
	int failcount =0;

	printf ("ADVENTURER TEST\n");		
	initializeGame(numberofPlayers, k, 2000, &state); //save the original state of the game after being initialized
	printf ("Game Succesfully initialized\n");
	printf ("Randomizing Game State variables\n");
	
	//change hand count
	//change deck count (include 0)
	// change hand and deck (include all possible combinations 
	

	for (int count = 0; count < 100; count++){
		
		state.deckCount[0] = rand()%50;
		//printf ("Deckcount = %d\n", state.deckCount[0]);
	
		for (int i=0; i<state.deckCount[0]; i++){
			state.deck[0][i]= possibleCards [rand() %17];
		}
		   for (int j =0; j<state.handCount[0]; j++){
			state.hand[0][j] = possibleCards [(rand() %17)];
			//state.handCount[0]++;
			//printf ("State Hand Player %d Position %d = %d\n", i, j, state.hand[i][j]);	
			//		}	
		}		
		
	treassurecount1 = treassureCount (state, 0);
	handCount1 = state.handCount[0];
	cardEffect (adventurer, 0, 0, 0, &state, 0, 0);
	
	/*for (int i; i<state.handCount[0]; i++){
	printf ("card %d = %d \n", i, state.hand[0][i]);
	}
	*/
		
	treassurecount2 =treassureCount(state, 0);
	handCount2 = state.handCount[0];

	if (treassurecount2 == treassurecount1+2){
	//printf ("Test 1 Passed, current player has 2 additional treassure cards on their hand\n");
	}
	else{
	printf ("Test 1 Failed, Adventurer card didn't add the correct amount of treassures to player's hand\n");
	failcount++;
	}

//	for (int i = 0; i<state.deckCount[0];){ 
//	drawCard (0, &state);
//	discardCard (0,0,&state,0);
	//printf ("Discard card Count %d\n", state.discardCount[0]);		
	//printf ("Deck Count %d\n", state.deckCount[0]);
	//printf ("Played Cards count %d\n", state.playedCardCount); 
//	}

//	treassurecount1 = treassureCount (state, 0);
//	cardEffect (adventurer, 0, 0, 0, &state, 0, 0);
	
	/*for (int i; i<state.handCount[0]; i++){
	printf ("card %d = %d \n", i, state.hand[0][i]);
	}
	*/
		
	treassurecount2 =treassureCount(state, 0);
	if (treassurecount2 == treassurecount1+2){
	//printf ("Test 2 Passed, adventurer handled empty deck properly\n");
	}
	else{
	printf ("Test 2 Failed, Adventurer card didn't handle empty deck properly\n");
	failcount++;
	}
	if (handCount2 < handCount1+1){
	//printf ("Test 3 Passed, correct hand count after adventurer\n");
	}
	else{
	printf ("Test 3 Failed, hand count after adventurer is not equal to expected\n");
	failcount ++;
	}
}
	printf ("%d/300 Tests Failed", failcount);
	return 0;
}
