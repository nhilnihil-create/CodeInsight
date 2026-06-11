#include <bits/stdc++.h>
using namespace std;
#define all(V) V.begin(),V.end()
using ll = long long;

int main() {
	string S;
	cin >> S;
	int ss = S.size();
	int C = 0;
	for (int i = 0;i < ss;i++) {
		if (i % 2) {
			if (S[i] == 'g')
				C++;
		}
		else {
			if (S[i] == 'p')
				C--;
		}
	}
	cout << C << endl;
}