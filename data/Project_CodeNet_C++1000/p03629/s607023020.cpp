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

const int N = (int)2e5 + 7;
const int inf = (int)1e9 + 7;
const int mod = (int)1e9 + 7;
const ll linf = (ll)1e18 + 7;

const int dx[] = {-1, 0, 1, 0, 1, -1, -1, 1};
const int dy[] = {0, 1, 0, -1, 1, -1, 1, -1};

using namespace std;

int n;
char s[N];
int nxt[26][N];

int dp[N], go[N];
int calc(int v = 0) {
	if (v > n) return 0;
	if (~dp[v]) return dp[v];

	int res = inf;
	rep(i, 0, 25) {
		int j = nxt[i][v + 1];
		int cur = calc(j) + 1;
		if (cur < res) {
			res = cur;
			go[v] = i;
		}
	}

	return dp[v] = res;
}
int main() {
	#ifdef IOI2018
		freopen ("in.txt", "r", stdin);
	#endif
	Kazakhstan
	cin >> (s + 1);
	n = strlen(s + 1);
	// end of input
	
	rep(i, 0, 25) nxt[i][n + 1] = n + 1;
	per(i, n, 1) {
		rep(j, 0, 25) nxt[j][i] = nxt[j][i + 1];
		nxt[s[i] - 'a'][i] = i;
	}
	memset(dp, -1, sizeof(dp));
	calc();
	int p = 0;
	string ans;
	while (p <= n) {
		ans += go[p] + 'a';
		p = nxt[go[p]][p + 1];
	}
	cout << ans;
	ioi
}
