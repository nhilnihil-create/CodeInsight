#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 30;
 
int main() {
	ll q, h, s, d, n;
	cin >> q >> h >> s >> d >> n;
	ll pq=8*q, ph=4*h, ps=2*s;
	ll mi = min(pq, min(ph, min(ps, d)));
	
	ll ans= 0;
	if (n%2==0) {
		ans = n / 2 * mi;
	}
	else {
		ans += n / 2 * mi;
		ans += min(q*4, min(h*2, s));
	}
	cout << ans << endl;
	return 0;
}