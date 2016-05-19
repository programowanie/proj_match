#include "Player.h"
#include <stdlib.h>
#include <fstream>
#include <iterator>
#include <iostream>

using namespace std;

vector <string>Player::names_FCB;
vector <string>Player::names_CFC;

void Player::init_CFC()
{
	ifstream my_file("Chelsea.dat");
	copy(istream_iterator <string> (my_file),
		istream_iterator<string>(),
		back_inserter(names_CFC));
	my_file.close();
}

void Player::init_FCB()
{
	ifstream my_file("Barca.dat");
	copy(istream_iterator <string> (my_file),
		istream_iterator<string>(),
		back_inserter(names_FCB));
	my_file.close();
}

int randomValue()
{
	return 50 + rand() % 49;	
}

Player::Player(int team)
{

	if(team==1)
	{

		static int amountOfNames = (init_CFC() , names_CFC.size());
		static bool *tab=new bool[names_CFC.size()];
		for(int i=0;i<names_CFC.size();i++) tab[i]=0;
		

		while(1){
			int amount =rand() % amountOfNames;
			if(tab[amount]==0){
				_name = names_CFC[amount];
			break;	
			}
		}
	 	_pass= randomValue();
	 	_defPass= randomValue();
	 	_defDribble= randomValue();
	 	_shot= randomValue();
	 	_dribble= randomValue();	
	}
	else if(team==2)
	{
		static int amountOfNames = (init_FCB() , names_FCB.size());
		static bool *tab=new bool[names_FCB.size()];
		int amount =rand() % amountOfNames;

		while(1){
			if(tab[amount]==0){
				_name = names_FCB[amount];
			break;	
			}
		}
		_pass= randomValue();
		_defPass= randomValue();
	 	_defDribble= randomValue();
		_shot= randomValue();
		_dribble= randomValue();
	}
	else cout<<"<Blad konstruktora>"<<endl;
	
}

string Player::description()
{

	return _name + 
	" shot: " + to_string(_shot) + 
	"\n\t" +
	"Pass defence: " + to_string(_defPass) + 
	" Dribble defence: " + to_string(_defDribble) + 
		"\n\t pass: " + to_string(_pass) + 
		"\n\t dribble " + to_string(_dribble);
}