#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

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
	int treassurecount1 =0;
	int treassurecount2 =0;
	int handCount1 =0;
	int handCount2 =0;
	
	printf ("ADVENTURER TEST\n");		
	initializeGame(numberofPlayers, k, 2000, &state); //save the original state of the game after being initialized
	printf ("Game Succesfully initialized\n");
	
	/*for (int i; i<state.handCount[0]; i++){
	printf ("State card %d = %d \n", i, state.hand[0][i]);  
	}

	//for (int i; i<test1.handCount[0]; i++){
	//printf ("Test card %d = %d \n", i, state.hand[0][i]);  
	//}
	*/
	treassurecount1 = treassureCount (state, 0);
	handCount1 = state.handCount[0];
	cardEffect (adventurer, 0, 0, 0, &state, 0, 0);
	
	/*for (int i; i<state.handCount[0]; i++){
	printf ("card %d = %d \n", i, state.hand[0][i]);
	}
	*/
		
	treassurecount2 =treassureCount(state, 0);
	handCount1 = state.handCount[0];

	if (treassurecount2 == treassurecount1+2){
	printf ("Test 1 Passed, current player has 2 additional treassure cards on their hand\n");
	}
	else
	printf ("Test 1 Failed, Adventurer card didn't add the correct amount of treassures to player's hand\n");
	
	for (int i = 0; i<state.deckCount[0];){ 
	drawCard (0, &state);
	discardCard (0,0,&state,0);
	//printf ("Discard card Count %d\n", state.discardCount[0]);		
	//printf ("Deck Count %d\n", state.deckCount[0]);
	//printf ("Played Cards count %d\n", state.playedCardCount); 
	}

	treassurecount1 = treassureCount (state, 0);
	cardEffect (adventurer, 0, 0, 0, &state, 0, 0);
	
	/*for (int i; i<state.handCount[0]; i++){
	printf ("card %d = %d \n", i, state.hand[0][i]);
	}
	*/
		
	treassurecount2 =treassureCount(state, 0);
	if (treassurecount2 == treassurecount1+2){
	printf ("Test 2 Passed, adventurer handled empty deck properly\n");
	}
	else
	printf ("Test 2 Failed, Adventurer card didn't handle empty deck properly\n");
	
	if (handCount2 == handCount1+1){
	printf ("Test 3 Passed, correct hand count after adventurer\n");
	}
	else
	printf ("Test 3 Failed, hand count after adventurer is not equal to expected\n");
	
	return 0;
}
