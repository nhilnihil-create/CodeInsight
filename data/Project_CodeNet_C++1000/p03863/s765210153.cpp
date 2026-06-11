#include <bits/stdc++.h>
#define PI 3.14159265359
using namespace std;

int main() {
	string s;
	cin >> s;

	string winner = "";
	if ((s.size() % 2 == 1) && (s.at(0) == s.at(s.size() - 1))) {
		winner = "Second";
	}
	else if ((s.size() % 2 == 0) && (s.at(0) != s.at(s.size() - 1))) {
		winner = "Second";
	}
	else {
		winner = "First";
	}

	cout << winner << endl;
}