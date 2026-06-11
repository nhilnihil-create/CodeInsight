/// In The Name Of God

#include <bits/stdc++.h>

#define f first
#define s second

#define pb push_back
#define pp pop_back
#define mp make_pair

#define sz(x) (int)x.size()
#define sqr(x) ((x) * 1ll * (x))
#define all(x) x.begin(), x.end()

#define rep(i, l, r) for (int i = (l); i <= (r); i++)
#define per(i, l, r) for (int i = (l); i >= (r); i--)

#define Kazakhstan ios_base :: sync_with_stdio(0), cin.tie(0), cout.tie(0);

#define nl '\n'
#define ioi exit(0);

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const int N = (int)5e5 + 7;
const int inf = (int)1e9 + 7;
const int mod = (int)1e9 + 7;
const ll linf = (ll)1e18 + 7;

const int dx[] = {-1, 0, 1, 0, 1, -1, -1, 1};
const int dy[] = {0, 1, 0, -1, 1, -1, 1, -1};

using namespace std;

int n, L;
int a[N];
int main() {
	#ifdef wws
		freopen ("in.txt", "r", stdin);
	#endif
	Kazakhstan
	cin >> n >> L;
	rep(i, 1, n) {
		cin >> a[i];
	}
	int p = -1;
	rep(i, 1, n - 1) {
		if (a[i] + a[i + 1] >= L) {
			p = i;
		}
	}
	if (p == -1) cout << "Impossible", ioi;
	vector <int> ans;
	rep(i, p, n - 1) ans.pb(i);
	per(i, p - 1, 1) ans.pb(i);
	reverse(all(ans));
	cout << "Possible\n";
	for (auto it : ans) cout << it << nl;
	ioi
}
