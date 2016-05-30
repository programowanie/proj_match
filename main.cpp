#include "Player.h"
#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>


using namespace std;


bool didWin(int attack,int defence);
void actions(vector<Player>&vecA,vector<Player>&vecD,bool &whoAttacks,int &passes,
	int &dribles,int &ScoreA,int sizeOfTeam,Player &help);

#define MINUTE_INTERVAL 1500000

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
	
	bool whoAttacks=rand()%2 +1;
	int ScoreCFC=0,ScoreFCB=0;
	int dribles=0,passes=0;
	Player help(1);
	do{
		if(whoAttacks==1)		//atakuje CFC
		{
			actions(vecCFC,vecFCB,whoAttacks,passes,dribles, ScoreCFC,sizeOfTeam,help);
			
			

		}
		else		//atakuje FCB
		{
			actions(vecFCB,vecCFC,whoAttacks,passes,dribles, ScoreFCB,sizeOfTeam,help);
			
			

		}

	}while(Player::counter()<countdown);


	cout<<"\n\t\t\t\t\tWynik meczu:\n\t\t\t\t\tCFC "<<ScoreCFC<<":"<<ScoreFCB<<" FCB\n\n";
	cout<<"\t\t\t\t\t    Składy:\n\t\t\t\t Chlesea\n";
	for (int i=0;i<sizeOfTeam;i++)
	{
		cout<<"\t\t\t\t"<<vecCFC[i].goals() <<" "<<vecCFC[i].name()<<endl;
	}
	cout<<"\t\t\t\t Barca\n";
	for(int i=0;i<sizeOfTeam;i++)
	{
		cout<<"\t\t\t\t"<<vecFCB[i].goals()<<" "<<vecFCB[i].name()<<endl;
	}

	cout<<"passes: "<<passes<<" i dribles "<<dribles<<"!\n";




/*
	cout<<"\n\t\t\t\t\tStatystyki:\n";
	for(int i=0;i<sizeOfTeam;i++)
	{
		cout<<vecCFC[i].description()<<endl;
	}
	for(int i=0;i<sizeOfTeam;i++)
	{
		cout<<vecFCB[i].description()<<endl;
	}
*/

}

void actions(vector<Player>&vecA,vector<Player>&vecD,bool &whoAttacks,int &passes,
	int &dribles,int &ScoreA,int sizeOfTeam,Player &help)
{
	
	for(int i=0;i<sizeOfTeam+1;i++)		// +1 żeby zakończyć strzałem lub pudłem
			{usleep(MINUTE_INTERVAL);
				if(i<sizeOfTeam-1)					//jesli ma komu podac
				{	if((vecA[i]).PassOrDribble())
					{
						//zawodnik podaje

						if( ! didWin(	(vecA[i]).pass(),(vecD[i]).defPass()	)  )
						{
							cout<<"\t "<<(vecD[i].name())<<" przejal pilke od "
								<<(vecA[i]).name() <<"\n";
							help=vecD[i];
							vecD[i]=vecD[0];
							vecD[0]=help;	
							whoAttacks=!whoAttacks;
							break;	
						} 
						cout<<(vecA[i]).name()<<" podaje do "<< (vecA[i+1]).name()<<"\n";
						passes++;
					}
					else
					{
						//zawodnik drybluje
						if(! didWin(	(vecA[i]).dribble(),(vecD[i]).defDribble())	)
						{
							cout<<"\t "<<(vecD[i]).name()<<" przejal pilke od "
								<<(vecA[i]).name()<<"\n";
							help=vecD[i];
							vecD[i]=vecD[0];
							vecD[0]=help;
							whoAttacks=!whoAttacks;
							break;
						}
						cout<<(vecA[i]).name()<<" mija "<<(vecD[i]).name()
							<<" dryblingiem"<<"\n";
							dribles++;
						if(i!=sizeOfTeam-1)	//gdy drybluje to idzie na kolejnego zawodnika
						{
	
							help=vecA[i];
							vecA[i]=vecA[i+1];
							vecA[i+1]=help;	
						}
						
					}

				}
				else //jeesli nie ma komu podac to albo musi kiwac albo strzelac
				{	
					if(i==sizeOfTeam-1)	// jesli nie ma komu podac
					{
						//zawodnik drybluje
						if(! didWin(	(vecA[i]).dribble(),(vecD[i]).defDribble())	)
						{
							cout<<"\t "<<(vecD[i]).name()<<" przejal pilke od "
								<<(vecA[i]).name()<<"\n";
							help=vecD[i];
							vecD[i]=vecD[0];
							vecD[0]=help;
							whoAttacks=!whoAttacks;
							break;
						}
						cout<<(vecA[i]).name()<<" mija "<<(vecD[i]).name()
							<<" dryblingiem"<<"\n";
							dribles++;
						if(i!=sizeOfTeam-1)	//gdy drybluje to idzie na kolejnego zawodnika
						{
							
							help=vecA[i];
							vecA[i]=vecA[i+1];
							vecA[i+1]=help;	
						}
					}
					else if(i==sizeOfTeam)  //jesli strzela
					{
						if(! didWin( (vecA[i-1]).shot() ,(100-(vecA[i-1]).shot())	)	)
						{
							cout<<"\t"<<(vecA[i-1]).name()<<" pudluje! "<<"\n";
							whoAttacks=!whoAttacks;
							break;
						}
						cout<<"\t"<<(vecA[i-1]).name()<<" strzela gola! "<<"\n";
						whoAttacks=!whoAttacks;
						vecA[i-1].goalsPlus();
						ScoreA++;

					}
				}

			}
			

}


bool didWin(int attack, int defence)
{
	Player::counterPlus();
	//Player::_counter++;
	cout<<"\n"<<Player::counter()<<endl;
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