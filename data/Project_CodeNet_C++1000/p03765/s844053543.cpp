#define _USE_MATH_DEFINES
#include "bits/stdc++.h"
#define rep(i,a,b) for (int i = (a); i < (b); i++)
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> P;
typedef complex<double> com;
const int mod = 1e9 + 7;
const int MOD = 998244353;
const int inf = 2e9;



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s, t; cin >> s >> t;
	int q; cin >> q;
	vector<int> sums(s.size()+1, 0), sumt(t.size()+1, 0);
	rep(i, 0, s.size()){
		sums[i + 1] = (sums[i] + (s[i] == 'A' ? 1 : 2)) % 3;
	}
	rep(i, 0, t.size()) {
		sumt[i + 1] = (sumt[i] + (t[i] == 'A' ? 1 : 2)) % 3;
	}
	rep(i, 0, q) {
		int a, b, c, d; cin >> a >> b >> c >> d;
		if ((sums[b] - sums[a-1]+3)%3 == (sumt[d] - sumt[c-1]+3)%3) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
