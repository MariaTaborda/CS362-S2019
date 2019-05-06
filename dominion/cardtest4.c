#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int CopperCount (struct gameState s, int player){
	int count = 0;
	for (int i =0; i<s.handCount[player]; i++){
	if (s.hand[player][i] == 4){
	count++;
	}
	}
	//printf ("Count for player %d =  %d \n", player+1, count);
	 
	return count; 
}

int main (){
	struct gameState state ;
	int numberofPlayers = 3; //Using this to make test a few cases of curpurse effect
	int k[10] = {adventurer, council_room, cutpurse, gardens, great_hall,
		outpost, sea_hag, smithy, tribute, village}; //random set for supplies
	int CoinCount1p1 =0;
	int CoinCount2p1 =0;
	int CopperCount1p2 =0;
	int CopperCount2p2 =0;
	int CopperCount1p3 =0;
	int CopperCount2p3 =0;

	printf ("SEA HAG TEST\n");			
	initializeGame(numberofPlayers, k, 2000, &state); // this will save the original state of the game after being initialized
	printf ("Succesfully initialized game \n");
	
	for (int i=0; i<5; i++){
	state.hand[1][i]= 5; //give all silvers to player 1 so there are't any coppers to discard
	state.handCount[1]++;
	//printf ("State card %d = %d \n", i, state.hand[1][i]);  
	}

	for (int i=0; i<5; i++){
	state.hand[2][i]= 4; //give all coppers to player 2 to check cutpurse functionality
	state.handCount[2]++;
	//printf ("State card %d = %d \n", i, state.hand[2][i]);  
	}
	
	//for (int i; i<test1.handCount[0]; i++){
	//printf ("Test card %d = %d \n", i, state.hand[0][i]);  
	//}
	

	state.hand[0][0] = 21;
	updateCoins (0, &state, 0);
	for (int i =0; i<state.handCount[0]; i++) {
	//printf ("Card %d is %d \n", i, state.hand[0][i]);
	}

	CoinCount1p1 = state.coins;
	//printf ("Coin count1 = %d", CoinCount1p1);
	CopperCount1p2 = CopperCount (state, 1);
	CopperCount1p3 = CopperCount (state, 2);

	cardEffect (cutpurse, 0, 0, 0, &state, 0, 0);
//	printf ("Coin count2 = %d", CoinCount2p1);
	
	for (int i=0; i<state.handCount[0]; i++) {
	//printf ("Card %d is %d \n", i, state.hand[0][i]);
	}

	CoinCount2p1 = state.coins;
//	printf ("Coin count2 = %d", CoinCount2p1);

	CopperCount2p2 = CopperCount (state, 1);
	CopperCount2p3 = CopperCount (state, 2);

	if (CoinCount1p1 == CoinCount2p1-2){
	printf ("Test 1 passed, sea_hag has correctly updated coin count for player using it\n");
	}
	else{
	printf ("Test 1 failed, player's coin count was not updated\n ");
	}

	if (CopperCount1p2 == CopperCount2p2+1 || CopperCount1p2 == 0) {
	printf ("Test 2 passed, sea_hag has correctly handled curses\n");
	}
	else
	printf ("Test 2 failed, seahag has not handled curses correctly\n");
	
	
	return 0;
}
