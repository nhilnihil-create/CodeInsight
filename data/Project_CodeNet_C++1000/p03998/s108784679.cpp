#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<string> hand(3);
	for(int i = 0; i < 3; i++) cin >> hand.at(i);

	int turn = 0;
	while(true) {
		if(hand.at(turn) == "") break;
		char next = hand.at(turn).at(0);
		hand.at(turn).erase(hand.at(turn).begin());
		switch(next) {
			case 'a': turn = 0; break;
			case 'b': turn = 1; break;
			case 'c': turn = 2; break;
			default: break;
		}
	}

	switch(turn) {
		case 0: cout << "A" << endl; break;
		case 1: cout << "B" << endl; break;
		case 2: cout << "C" << endl; break;
		default: break;
	}
}