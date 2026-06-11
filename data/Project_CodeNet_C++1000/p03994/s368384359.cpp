#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,a,n) for(int i=(a); i<(n); i++)
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string S; ll K;
	cin >> S >> K;
	int to_a;
	rep(i, S.size()) {
		to_a = ('z'-S[i]+1) % 26;
		// cout << S[i] << " " << to_a << endl;
		if (K >= to_a) {
			S[i] = 'a';
			K -= ll(to_a);
		}
	}
	if (K) {
		S.back() += (K%26);
	}
	cout << S << endl;
}