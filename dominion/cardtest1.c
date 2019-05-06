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
	struct gameState state, test1 ;
	int numberofPlayers = 2; //Using this to make comparison easier
//	int init;
	int k[10] = {adventurer, council_room, cutpurse, gardens, great_hall,
		outpost, sea_hag, smithy, tribute, village}; //random set for supplies
	int treassurecount1 =0;
	int treassurecount2 =0;
	printf ("ADVENTURER TEST 2\n");
	initializeGame(numberofPlayers, k, 2000, &state); // this will save the original state of the game after being initialized
	printf ("Game initialized Succesfully\n");
	
	memcpy (&test1, &state, sizeof(struct gameState)); // copy the initialized game into a test struct to run unit test
	//memcpy (&test2, &state, sizeof(struct gameState));
	
	/*for (int i; i<state.handCount[0]; i++){
	printf ("State card %d = %d \n", i, state.hand[0][i]);  
	}

	//for (int i; i<test1.handCount[0]; i++){
	//printf ("Test card %d = %d \n", i, state.hand[0][i]);  
	//}
	*/

	treassurecount1 = treassureCount (state, 0);
	cardEffect (adventurer, 0, 0, 0, &state, 0, 0);
	
	/*for (int i; i<state.handCount[0]; i++){
	printf ("card %d = %d \n", i, state.hand[0][i]);
	}
	*/
		
	treassurecount2 =treassureCount(state, 0);

	if (treassurecount2 == treassurecount1+2){
	printf ("Test Passed, current player has 2 additional trassure cards on their hand");
	}
	else
	printf ("Test failed, Adventurer cards didn't add the correct amount of trassures to player's hand");
	
	return 0;
}
