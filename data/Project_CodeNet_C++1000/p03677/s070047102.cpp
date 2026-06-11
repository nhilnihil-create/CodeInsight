#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define rep(i,l,r) for(int i=(l);i<(r);++i)
#define per(i,l,r) for(int i=(r)-1;i>=(l);--i)
#define dd(x) cout << #x << " = " << x << ", "
#define de(x) cout << #x << " = " << x << endl
const int N = 2e5 + 7;
int add[N], a[N];
ll cut[N];
int n, m;
void solve() {
	rep(i, 0, n) scanf("%d", a + i);
	fill_n(add, 2 * m, 0);
	fill_n(cut, 2 * m, 0);
	ll ans = 0;
	rep(i, 0, n - 1) {
		int s = a[i], t = a[i + 1];
		ans += t - s;
		add[s + 2]++;
		add[t + 1]--;
		cut[t + 1] += t - s - 1;
		if (s > t) {
			ans += m;
			cut[t + 1] += m;
			add[1]++;
			cut[1] -= m - s - 1; //s + 2 ~ m
		}
		//dd(s); de(t);
	}
	int cur = 0; ll tmp = 0, mx = 0;
	rep(i, 1, m + 1) {
		tmp -= cut[i];
		cur += add[i]; //de(cur);
		tmp += cur; //de(tmp);
		mx = max(mx, tmp);
	}
	printf("%lld\n", ans - mx);
}

int main() {
	while (~scanf("%d%d", &n, &m)) solve();
	return 0;
}