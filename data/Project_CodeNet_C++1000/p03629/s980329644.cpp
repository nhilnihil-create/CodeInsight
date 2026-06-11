#include "bits/stdc++.h"
using namespace std;

int main() {
	string S;
	long long N;
	map<char, bool> mp;
	long long COUNT = 26;
	vector<string> VS = { "" };
	cin >> S;
	for (int i = S.size() - 1; i >= 0; i--) {
		if (!mp[S[i]]) COUNT--, mp[S[i]] = true;
		VS[VS.size() - 1] = S[i] + VS[VS.size() - 1];
		if (COUNT == 0) {
			VS.push_back("");
			mp.clear();
			COUNT = 26;
		}
	}
	reverse(VS.begin(), VS.end());
	string ANS = "";
	mp.clear();
	for (char C : VS[0]) mp[C] = true;
	for (char C = 'a'; C <= 'z'; C++) if (!mp[C]) {
		ANS = ANS + C;
		mp.clear();
		break;
	}
	for (int i = 1; i < VS.size(); i++) {
		bool check = false;
		for (char C : VS[i]) {
			if (check) {
				mp[C] = true;
			}
			else if (C == ANS[ANS.size() - 1]) check = true;
		}
		for (char C = 'a'; C <= 'z'; C++) if (!mp[C]) {
			ANS = ANS + C;
			mp.clear();
			break;
		}
	}
	cout << ANS << endl;
}