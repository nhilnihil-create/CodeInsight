#include "bits/stdc++.h"
using namespace std;

int main() {
	string S;
	cin >> S;
	int size = S.size();
	sort(S.begin(),S.end());
	S.erase(unique(S.begin(), S.end()), S.end());
	if (size == S.size()) {
		cout << "yes"<<endl;
	}
	else {
		cout << "no"<<endl;
	}
}
