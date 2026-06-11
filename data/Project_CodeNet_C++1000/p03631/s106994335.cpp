#include "bits/stdc++.h"
using namespace std;

int main() {
	string S;
	cin >> S;
	string Scopy = S;
	reverse(S.begin(),S.end());
	if (S ==Scopy) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No"<<endl;
	}
}