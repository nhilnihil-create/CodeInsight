# include<bits/stdc++.h>
 
using namespace std;

#define int long long
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, int> pdi;
typedef pair<ll, ll> pll;
 
# define S second
# define F first
# define kill(x) return(cout << x << endl, 0)
# define debug(x) cerr<< #x << " : " << x << endl
# define ddebug(x, y) cerr<< #x << " : " << x  << ", " << #y << " : " << y << endl
# define sz(s) (int)s.size()
# define sq(x) (x) * (x)
# define PB(x) push_back(x)
# define smax(x, y) (x) = max((x), (y))
# define smin(x, y) (x) = min((x), (y))
# define all(x) x.begin(), x.end()
# define SP fixed << setprecision(10)
# define UB upper_bound 

const int MAXN = 2000 + 10;
int a[MAXN], 
    mn[MAXN];

int32_t main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n, x;
	cin >> n >> x;
	for (int i = 0; i < n; i ++)
		cin >> a[i];

	memset(mn, 63, sizeof mn);
	int ans = LLONG_MAX;
	for (int i = 0; i <= n; i ++)
	{
		int cur = i * x;
		for (int j = 0; j < n; j ++)
		{
			smin(mn[j], a[(j - i + n) % n]);
			cur += mn[j];
		}
		smin(ans, cur);
	}
	cout << ans << endl;

	return 0;
}
