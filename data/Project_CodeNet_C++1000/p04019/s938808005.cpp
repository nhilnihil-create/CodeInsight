#include <bits/stdc++.h>
using namespace std;
int main() {
	string s;
	cin >> s;
	vector<bool> a(4, false);
	for (int i = 0; i < s.length(); i++) {
		if (s.at(i) == 'N')a.at(0)=true;
		else if (s.at(i) == 'W')a.at(1) = true;
		else if (s.at(i) == 'S')a.at(2) = true;
		else if (s.at(i) == 'E')a.at(3) = true;
	}
	if ((a.at(0) ^ a.at(2)) || (a.at(1) ^ a.at(3))) {
		cout << "No" << endl;
	}
	else cout << "Yes" << endl;
}