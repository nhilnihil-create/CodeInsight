# include<bits/stdc++.h>
 
using namespace std;
 
# define int long long
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

const int MAXN = 100 * 1000 + 10;
int a[MAXN];

int32_t main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i ++)
		cin >> a[i];

	int x = 2, ans = a[0] - 1;
	for (int i = 1; i < n; i ++)
	{
		if (a[i] == x)
			x ++;
		else
			ans += (a[i] + x - 1) / x - 1;

		ddebug(a[i], x);
		debug(ans);
		cerr << endl;
	}
	cout << ans << endl;

	return 0;
}
