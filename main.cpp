#include "Player.h"
#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


using namespace std;




int main(int argc, char const *argv[])
{
	int sizeOfTeam=5;//atoi(argv[1]);
	int countdown=100;//atoi(argv[2]);

	vector <Player > vecCFC;
	vector <Player > vecFCB;

	
	for(int i=0;i<sizeOfTeam;i++)
	{
		Player obiekt=Player(1);
		vecCFC.push_back(obiekt	);
	}
	for(int i=0;i<sizeOfTeam;i++)
	{
		Player obiekt=Player(2);
		vecFCB.push_back(obiekt	);
	}




}