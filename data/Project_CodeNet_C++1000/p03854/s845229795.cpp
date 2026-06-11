#include "bits/stdc++.h"
using namespace std;

int main() {
	string S; cin >> S;
	reverse(S.begin(), S.end());
	long long pos = 0;
	while (pos < S.size()) {
		if (pos < S.size() - 4 && S.at(pos) == 'm' && S.at(pos + 1) == 'a' && S.at(pos + 2) == 'e' && S.at(pos + 3) == 'r' && S.at(pos + 4) == 'd') {
			pos += 5;
		}
		else if (pos < S.size() - 4 && S.at(pos) == 'e' && S.at(pos + 1) == 's' && S.at(pos + 2) == 'a' && S.at(pos + 3) == 'r' && S.at(pos + 4) == 'e') {
			pos += 5;
		}
		else if (S.at(pos) == 'r' && pos < S.size() - 1 && S.at(pos + 1) == 'e') {
			if (pos < S.size() - 5 && S.at(pos + 2) == 's' && S.at(pos + 3) == 'a' && S.at(pos + 4) == 'r' && S.at(pos + 5) == 'e') {
				pos += 6;
			}
			else if (pos < S.size() - 4 && S.at(pos + 2) == 'm' && S.at(pos + 3) == 'a' && S.at(pos + 4) == 'e' && S.at(pos + 5) == 'r' && S.at(pos + 6) == 'd') {
				pos += 7;
			}
			else {
				cout << "NO" << endl;
				return 0;
			}
		}
		else {
			cout << "NO" << endl;
			return 0;
		}
	}
	if (pos != S.size()) cout << "NO" << endl;
	else cout << "YES" << endl;
}
