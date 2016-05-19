#pragma once

#include <string>
#include <vector>

using namespace std;

class Player
{
	static counter;
	static vector <string> names_CFC;
	static vector <string> names_FCB;
	string _name;
	int _pass,		_dribble,	_shot;
	int _defPass,	_defDribble;
	static void init_FCB();
	static void init_CFC();


	public:
		Player(int team);
		//~PLayer();
		int pass() {return _pass};
		int dribble() {return _dribble};
		int shot() {return _shot};
		int defPass() {return _defPass};
		int defDribble() {return _defDribble};


		string() description();



}