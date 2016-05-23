#pragma once

#include <string>
#include <vector>

using namespace std;



class Player
{


	static vector <string> names_CFC;
	static vector <string> names_FCB;
	string _name;
	int _pass,		_dribble,	_shot;
	int _defPass,	_defDribble;
	static void init_FCB();
	static void init_CFC();
	static int _counter;
	int _goals;

	public:
		Player(int team);
		//~PLayer();
		static void counterPlus(){	_counter++;	}
		static int counter(){return _counter;}
		bool PassOrDribble();
		int pass() {return _pass;}
		int dribble() {return _dribble;}
		int shot() {return _shot;}
		int defPass() {return _defPass;}
		int defDribble() {return _defDribble;}
		string name(){return _name;}
		void goalsPlus(){_goals++;}
		int goals(){return _goals;}


		
		
		

		string description();



};