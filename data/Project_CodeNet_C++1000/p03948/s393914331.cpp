#include <bits/stdc++.h>
using namespace std;
 
//#pragma GCC optimize("O3")
//#pragma GCC target("sse4")
 
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFOR(i, b, a) for(int i = (b) - 1; i >= (a); --i)
#define FILL(a, value) memset(a, value, sizeof(a))
 
#define SZ(a) (int)((a).size())
#define ALL(a) a.begin(), a.end()
 
typedef long long LL;
typedef pair<int, int> PII;

const int INF = 1000 * 1000 * 1000 + 7;
const int MAX = 1 << 17;

int n, t;
int a[MAX];

int solve()
{
	int d = 0, mn = INF, res = 0;
	FOR(i, 0, n)
	{
		if(a[i] - mn > d)
		{
			d = a[i] - mn;
			res = 0;
		}
		if(a[i] - mn == d)
			res++;
		mn = min(mn, a[i]);
	}
	return res;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> t;
	FOR(i, 0, n)
		cin >> a[i];
	int ans = solve();
	reverse(a, a + n);
	FOR(i, 0, n)
		a[i] = -a[i];
	ans = min(ans, solve());
	cout << ans << "\n";
	return 0;
}