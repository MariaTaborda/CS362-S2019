#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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
	srand (time(NULL));
	struct gameState state ;
	int numberofPlayers = 3; //Using this to make test a few cases of curpurse effect
	int k[10] = {adventurer, council_room, cutpurse, gardens, great_hall,
		outpost, sea_hag, smithy, tribute, village}; //random set for supplies
	int possibleCards[17] = {4, 1, 2, 3, 0, 5, 6, 7, 8, 21, 10, 16, 23, 25, 13, 19, 14};

	
	int CoinCount1p1 =0;
	int CoinCount2p1 =0;
	int CopperCount1p2 =0;
	int CopperCount2p2 =0;
	int CopperCount1p3 =0;
	int CopperCount2p3 =0;
	int passcount =0;
	int failcount =0;

	printf ("CUTPURSE TEST\n");			
	initializeGame(numberofPlayers, k, 2000, &state); // this will save the original state of the game after being initialized
	printf ("Succesfully initialized game \n");
	printf ("Randomizng Player's Hands \n");
	//state.hand[0][0] = 21; // add cutpurse to hand
	//updateCoins (0, &state, 0);

	for (int count = 0; count < 1000; count++){
		for (int i=1; i<3; i++){
		   for (int j =0; j<5; j++){
			state.hand[i][j] = possibleCards [(rand() %17)];
			state.handCount[i]++;
			//printf ("State Hand Player %d Position %d = %d\n", i, j, state.hand[i][j]);	
		}	
	}


	state.hand[0][0] = 21; // add cutpurse to hand
	updateCoins (0, &state, 0);
	//for (int i =0; i<state.handCount[0]; i++) {
	//printf ("Card %d is %d \n", i, state.hand[0][i]);
	//}

	CoinCount1p1 = state.coins;
	//printf ("Coin count1 = %d", CoinCount1p1);
	CopperCount1p2 = CopperCount (state, 1);
	CopperCount1p3 = CopperCount (state, 2);

	cardEffect (cutpurse, 0, 0, 0, &state, 0, 0);
//	printf ("Coin count2 = %d", CoinCount2p1);
	
	//for (int i=0; i<state.handCount[0]; i++) {
	//printf ("Card %d is %d \n", i, state.hand[0][i]);
	//}

	CoinCount2p1 = state.coins;
	//printf ("Coin count2 Player1 = %d\n", CoinCount2p1);

	CopperCount2p2 = CopperCount (state, 1);
	CopperCount2p3 = CopperCount (state, 2);
	//printf ("Coin count player 2 before = %d and After = %d\n", CopperCount1p2, CopperCount2p2);
	//printf ("Coin count player 3 before = %d and After = %d\n", CopperCount1p3, CopperCount2p3);
	//printf ("Coin count player 2 before = %d and After = %d\n", CoinCount2p1);


	
	//printf ("Running Asserts\n");
	if (CoinCount1p1 == CoinCount2p1-2){
	//printf ("Test 1 passed, Cutpurse has correctly updated coin count for player using it\n");
	passcount++;
	}
	else{
	printf ("Test 1 failed, player's coin count was not updated\n ");
	failcount++;
	}

	if ((CopperCount1p2 == CopperCount2p2+1 || CopperCount1p2 == 0)&& (CopperCount1p3 == CopperCount2p3+1 || CopperCount1p3 ==0)){
	//printf ("Test 2 passed, Cutpurse has correctly handled player with no copper\n");
	passcount++;
	}
	else{
	printf ("Test 2 failed, Cutpurse has not correctly handled player's copper count\n");
	failcount++;
	}
	}

	printf ("Run 2000 cases, %d Passed and %d Failed\n", passcount, failcount);

	return 0;
}
