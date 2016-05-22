#include "Player.h"
#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


using namespace std;


bool didWin(int attack,int defence);
int Player::_counter=0;

int main(int argc, char const *argv[])
{	
	srand(time(NULL));
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
	cout<<"!"<<whoAttacks<<"!\n";
	
	do{
		if(whoAttacks==1)		//atakuje CFC
		{
			for(int i=0;i<sizeOfTeam+1;i++)		// +1 żeby zakończyć strzałem lub pudłem
			{
				if(i<sizeOfTeam-1)					//jesli ma komu podac
				{	if((vecCFC[i]).PassOrDribble())
					{
						//zawodnik podaje
						if( ! didWin(	(vecCFC[i]).pass(),(vecFCB[i]).defPass()	)  )
						{
							cout<<"\t "<<(vecFCB[i].name())<<" przejal pilke od "
								<<(vecCFC[i]).name() <<"\n";
							whoAttacks=0;
							break;	
						} 
						cout<<(vecCFC[i]).name()<<" podaje do "<< (vecCFC[i+1]).name()<<"\n";
					}
					else
					{
						//zawodnik drybluje
						if(! didWin(	(vecCFC[i]).dribble(),(vecFCB[i]).defDribble())	)
						{
							cout<<"\t "<<(vecFCB[i]).name()<<" przejal pilke od "
								<<(vecCFC[i]).name()<<"\n";
							whoAttacks=0;
							break;
						}
						cout<<(vecCFC[i]).name()<<" mija "<<(vecFCB[i]).name()
							<<" dryblingiem"<<"\n";
					}

				}
				else //jeesli nie ma komu podac to albo musi kiwac albo strzelac
				{	
					if(i==sizeOfTeam-1)	// jesli nie ma komu podac
					{
						//zawodnik drybluje
						if(! didWin(	(vecCFC[i]).dribble(),(vecFCB[i]).defDribble())	)
						{
							cout<<"\t "<<(vecFCB[i]).name()<<" przejal pilke od "
								<<(vecCFC[i]).name()<<"\n";
							whoAttacks=0;
							break;
						}
						cout<<(vecCFC[i]).name()<<" mija "<<(vecFCB[i]).name()
							<<" dryblingiem"<<"\n";
					}
					else if(i==sizeOfTeam)  //jesli strzela
					{
						if(! didWin( (vecCFC[i-1]).shot() ,(100-(vecCFC[i-1]).shot())	)	)
						{
							cout<<(vecCFC[i-1]).name()<<" pudluje! "<<"\n";
							whoAttacks=0;
							break;
						}
						cout<<(vecCFC[i-1]).name()<<" strzela gola! "<<"\n";
						whoAttacks=0;

					}
				}

			}
			

		}
		else		//atakuje FCB
		{
			for(int i=0;i<sizeOfTeam+1;i++)		// +1 żeby zakończyć strzałem lub pudłem
			{
				if(i<sizeOfTeam-1)					//jesli ma komu podac
				{	if((vecFCB[i]).PassOrDribble())
					{
						//zawodnik podaje
						if( ! didWin(	(vecFCB[i]).pass(),(vecCFC[i]).defPass()	)  )
						{
							cout<<"\t "<<(vecCFC[i].name())<<" przejal pilke od "
								<<(vecFCB[i]).name() <<"\n";
							whoAttacks=1;
							break;	
						} 
						cout<<"\t\t"<<(vecFCB[i]).name()<<" podaje do "<< (vecFCB[i+1]).name()<<"\n";
					}
					else
					{
						//zawodnik drybluje
						if(! didWin(	(vecFCB[i]).dribble(),(vecCFC[i]).defDribble())	)
						{
							cout<<"\t "<<(vecCFC[i]).name()<<" przejal pilke od "
								<<(vecFCB[i]).name()<<"\n";
							whoAttacks=1;
							break;
						}
						cout<<"\t\t"<<(vecFCB[i]).name()<<" mija "<<(vecCFC[i]).name()
							<<" dryblingiem"<<"\n";
					}

				}
				else //jeesli nie ma komu podac to albo musi kiwac albo strzelac
				{	
					if(i==sizeOfTeam-1)	// jesli nie ma komu podac
					{
						//zawodnik drybluje
						if(! didWin(	(vecFCB[i]).dribble(),(vecCFC[i]).defDribble())	)
						{
							cout<<"\t "<<(vecCFC[i]).name()<<" przejal pilke od "
								<<(vecFCB[i]).name()<<"\n";
							whoAttacks=1;
							break;
						}
						cout<<"\t\t"<<(vecFCB[i]).name()<<" mija "<<(vecCFC[i]).name()
							<<" dryblingiem"<<"\n";
					}
					else if(i==sizeOfTeam)  //jesli strzela
					{
						if(! didWin( (vecFCB[i-1]).shot() ,(100-(vecFCB[i-1]).shot())	)	)
						{
							cout<<(vecFCB[i-1]).name()<<" pudluje! "<<"\n";
							whoAttacks=1;
							break;
						}
						cout<<"\t\t"<<(vecFCB[i-1]).name()<<" strzela gola! "<<"\n";
						whoAttacks=1;

					}
				}

			}
			

		}




	}while(Player::counter()<countdown);




}
bool didWin(int attack, int defence)
{
	Player::counterPlus();
	//Player::_counter++;
	int sum=attack+defence;

	bool *tab= new bool[sum];

	for (int i=0;i<defence;i++)
	{
		tab[i]==0;	//loose probability
	}
	for(int i=defence;i<sum;i++)
	{
		tab[i]=1;	//succes probability
	}

	int returned= tab[rand()%sum];
	delete [] tab;
	tab=NULL;

	return returned;

}