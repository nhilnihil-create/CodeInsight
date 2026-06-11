#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << # x << "; "<< x << endl


int main() {
	string S;
	cin >> S;
	for (int i = 0; i < S.size() - 1; i++) {
		for (int j = i + 1; j < S.size(); j++) {
			if (S.at(i) != S.at(j) && i < S.size() - 2) {
				continue;
			}
			else if (S.at(i) != S.at(j) && i == S.size() - 2) {
				cout << "yes" << endl;
			}
			else if (S.at(i) == S.at(j)) {
				cout << "no" << endl;
				exit(0);
			}
		}
	}
}