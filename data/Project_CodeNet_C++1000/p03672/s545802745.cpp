#include "bits/stdc++.h"
using namespace std;

int main() {
	string S;
	cin >> S;
	for (int i = (S.size() / 2-1);i>=1;--i) {
		string S1 = S.substr(0, i);
		string S2 = S.substr(i, i);
		if (S1 ==S2) {
			cout  << i * 2 << endl;
			return 0;
		}
	}
	return 0;
}