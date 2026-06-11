#include "bits/stdc++.h"
using namespace std;

int main() {
	string S;
	cin >> S;
	bool b0 = false;
	if (S[0] == S[S.size()-1]) {
		b0 = true;
	}
	bool b1 = false;
	if (0 == S.size()%2) {
		b1 = true;
	}
	if (b0 ==b1) {
		cout << "First" << endl;
	}
	else {
		cout << "Second" << endl;
	}
	return 0;
}
