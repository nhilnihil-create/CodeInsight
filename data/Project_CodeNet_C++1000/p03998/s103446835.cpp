#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	vector<string>abc(3);
	for (int i = 0; i < 3; i++)cin >> abc.at(i);
	int turn = 0;
	while (true) {
		if (abc.at(turn).length() == 0) {
			char s = 'A' + turn;
			cout << s << endl;
			return 0;
		}
		char x = abc.at(turn).at(0);
		if(abc.at(turn).length()>=1)abc.at(turn) = abc.at(turn).substr(1);
		turn = x - 'a';
		//cout << abc.at(0) << " " << abc.at(1) << " " << abc.at(2) << endl;
	}
}