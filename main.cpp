#include "Player.h"
#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


using namespace std;


//bool didWin(vector<Player> vecOfAttack, vector<Player> vecOfDeffn int sizeOfTeam);
bool PassOrDribble (int pass,int dribble);

int main(int argc, char const *argv[])
{
	int sizeOfTeam=atoi(argv[1]);
	int countdown=atoi(argv[2]);

	vector <Player > vecCFC;
	vector <Player > vecFCB;

	//wybranie drużyn
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

	//mecz
	int whoAttacks=rand()%2 +1;

	do{
		if(whoAttacks==1)
		{
			for(int i=0;i<sizeOfTeam;i++)
			{
				if(PassOrDribble( 	(vecCFC[i].pass()),	(vecCFC[i].dribble())) )
				{
				//zawodnik podaje
					;
				}
				else
				{
				//zawodnik drybluje

				}

			}
			

		}
		else
			{;}




	}while(counter()<countdown);




}

bool PassOrDribble(int pass, int dribble)
{	
	srand(time(NULL));
	int sum=dribble+pass;
	bool *tab= new bool[sum];
	for (int i=0;i<dribble;i++)
	{
		tab[i]==0;	//dribble probability
	}
	for(int i=dribble;i<sum;i++)
	{
		tab[i]=1;	//pass probability
	}
	return tab[rand()%sum];



}

/*bool didWin()(vector<Player> vecOfAttack, vector<Player> vecOfDeff, int sizeOfTeam)
{

	for (int i=0;i<sizeOfTeam;i++)
	{


	}


}*/