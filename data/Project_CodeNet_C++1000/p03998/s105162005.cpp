#include <iostream>

using namespace std;

int main() {
	string SA, SB, SC;
	cin >> SA >> SB >> SC;

	int total_turn = SA.length() + SB.length() + SC.length();

	char turn = 'a';
	for (int i = 0; i < total_turn; i++) {
		//cout << "turn:" << (char)turn << endl;
		if (SA.length() == 0 && turn=='a') {
			cout << "A" << endl;
			return 0;
		}
		else if (SB.length() == 0 && turn == 'b') {
			cout << "B" << endl;
			return 0;
		}
		else if (SC.length() == 0 && turn == 'c') {
			cout << "C" << endl;
			return 0;
		}
		//cout << "---" << endl;
		if (turn == 'a') {
			turn = SA[0];
			SA = SA.erase(0, 1);
			//cout << SA << endl;
		}
		else if (turn == 'b') {
			turn = SB[0];
			SB = SB.erase(0, 1);
			//cout << SB << endl;
		}
		else if (turn == 'c') {
			turn = SC[0];
			SC = SC.erase(0, 1);
			//cout << SC << endl;
		}
	}
}
