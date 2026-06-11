#include "bits/stdc++.h"
using namespace std;

int main() {
	string S;
	cin >> S;
	string ansS;
	ansS += S[0];
	ansS += to_string(S.size()-2);
	ansS += S[S.size() - 1];
	cout << ansS << endl;
	return 0;
}