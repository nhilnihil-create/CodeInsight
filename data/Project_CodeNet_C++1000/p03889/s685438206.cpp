#include "bits/stdc++.h"
using namespace std;

int main() {
	string S, T = "";
	cin >> S;
	for (int i = 0; i < S.size(); i++) {
		if (S[i] == 'b') T = T + 'd';
		if (S[i] == 'd') T = T + 'b';
		if (S[i] == 'p') T = T + 'q';
		if (S[i] == 'q') T = T + 'p';
	}
	reverse(T.begin(), T.end());
	if (S == T) cout << "Yes";
	else cout << "No";
}