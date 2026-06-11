#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define rrep(i,n) for(int i=1;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int inf = 1001001001;
const int mod = 1000000007;

ll c[101][101];

void init() {
	c[0][0] = 1;
	for (int i = 0; i <= 100; ++i) {
		for (int j = 0; j <= i; ++j) {
			c[i + 1][j] += c[i][j];
			c[i + 1][j + 1] += c[i][j];
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	init();
	int n, a, b;
	cin >> n >> a >> b;
	vector<ll> v(n);
	rep(i, n) cin >> v[i];
	sort(rall(v));
	ll sum = 0;
	rep(i, a) sum += v[i];
	double ans1 = sum / (double)a;
	int cnt1 = 0, cnt2 = 0;
	rep(i, n) {
		if (v[i] == v[a - 1]) {
			cnt1++;
			if (i < a) cnt2++;
		}
	}
	ll ans2 = 0;
	if (cnt2 == a) {
		for (int i = a; i <= b; ++i) {
			ans2 += c[cnt1][i];
		}
	}
	else {
		ans2 += c[cnt1][cnt2];
	}
	cout.precision(10);
	cout << fixed << ans1 << endl;
	cout << ans2 << endl;
	return 0;
}
