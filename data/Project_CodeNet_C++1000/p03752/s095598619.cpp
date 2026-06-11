#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define rrep(i,n) for(int i=1;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define dunk(a) cout << (a) << "\n"
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int inf = 1001001001;
const int mod = 1000000007;

int counter(int a) {
	if (a == 0) return 0;
	return counter(a >> 1) + (a & 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	vector<ll> a(n);
	rep(i, n) cin >> a[i];

	ll ans = 100000000000;
	for (int bit = 0; bit < (1 << n); ++bit) {
		//bit番目が見えるように調節する
		//一番目は必ず見える
		ll res = 0;
		ll tmp = a[0];
		int cnt = 1;
		rrep(i, n) {
			if (tmp >= a[i] && bit & (1 << i)) {
				res += tmp - a[i] + 1;
				tmp++;
				cnt++;
			}
			else if (tmp < a[i]) {
				tmp = a[i];
				cnt++;
			}
			if (cnt >= k) ans = min(ans, res);
		}
	}

	dunk(ans);

	return 0;
}