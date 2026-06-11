#include "bits/stdc++.h"
using namespace std;


int main() {
	string S;
	cin >> S;
	string ansS;
	for (int i = 0;i<S.size();++i) {
		if (0 == i%2) {
			ansS += S[i];
		}
	}
	cout << ansS << endl;
	return 0;
}