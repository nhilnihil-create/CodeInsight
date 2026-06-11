#include"bits/stdc++.h"

#define rep(i, N) for(int i = 0;i < N;i++)

typedef long long ll;

const int mod = 1e9 + 7;

using namespace std;



int main(void) {
	string S; cin >> S;
	int ans = 0;

	for (int i = 0; i + 1 < S.length(); i++) {
		if (S[i] != S[i + 1])ans++;
	}

	cout << ans << endl;

	return 0;
}