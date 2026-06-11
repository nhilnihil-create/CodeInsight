#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(){
	string S;
	cin >> S;
	for (int i = 0; i < S.size(); i++) {
		for (int j = i+1; j < S.size(); j++) {
			if (S[i] == S[j]) {
				cout << "no" << endl;
				return 0;
			}
		}
	}
	cout << "yes" << endl;

	return 0;
}
