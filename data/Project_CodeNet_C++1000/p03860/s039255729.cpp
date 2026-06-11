#include "bits/stdc++.h"
using namespace std;

int main() {
	string S0, s;
	getline(cin, S0);
	for (int i = 0; i < S0.size(); i++)
	{
		if ((s = S0.at(i)) == " ") {
			s = S0.at(i + 1);
			break;
		}
	}
	
	cout << "A"+s+"C" << endl;
}