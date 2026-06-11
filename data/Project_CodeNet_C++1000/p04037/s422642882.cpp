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
#define int ll

int n;
int a[N];
int32_t main() {
	#ifdef wws
		freopen ("in.txt", "r", stdin);
	#endif
	Kazakhstan
	cin >> n;
	rep(i, 1, n) cin >> a[i];
	sort (a + 1, a + 1 + n, greater<int>());
	int p = 1;
	while (p + 1 <= a[p + 1]) p++;
	int x = a[p] - p, y = 0;
	rep(i, p + 1, n) {
		if (a[i] != p) break;
		y++;
	}
	if ((x | y) & 1) cout << "First";
	else cout << "Second";
	ioi
}
