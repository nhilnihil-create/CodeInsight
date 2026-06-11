#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define F first
#define S second

#define fo(i, n) for(int i = 1; i <= n; ++i)
#define rep(i, a, b) for(int (i) = (a); (i) < (b); ++(i))

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 200200;
const int mod = 1e9 + 7;
const ll INF = 1e18;

inline void add(int &x, int y)
{
	x += y;
	if(x >= mod) x -= mod;
	if(x < 0) x += mod;	
}

inline void mult(int &x, int y)
{
	x = x * 1ll * y % mod;
}

ll dp[N], n;
ll x[N];

ll t[4 * N];

inline void build(int v, int tl, int tr)
{
	
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	fo(i, n) cin >> x[i];
	int l = 1;
	dp[1] = 1, dp[2] = 2;
	fo(r, n)
	{
		if(r <= 2) continue;
		while(l < r && (x[r - 1] <= 2 * (r - 1) - 2 * l || x[r] < 2 * r - 2 * l))
			++l;
		dp[r] = r - l + 1;
	}
	ll res = 1;
	fo(i, n)
		res = res * (dp[i]) % mod;
	cout << res;
	return 0;	
}