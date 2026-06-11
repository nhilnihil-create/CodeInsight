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

const int MAXN = 200 * 1000 + 10;
int ans[MAXN];

int32_t main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n, x;
	cin >> n >> x;
	if (x == 1 || x == 2 * n - 1)
		kill("No");
	cout << "Yes" << endl;
	ans[n - 1] = x;
	ans[n] = 1;
	ans[n - 2] = 2 * n - 1;

	int a = 2;
	for (int i = 0; i < 2 * n - 1; i ++)
	{
		if (a == x)
			a ++;
		if (i <= n && i >= n - 2)
			continue;
		ans[i] = a;
		a ++;
	}
	for (int i = 0; i < 2 * n - 1; i ++)
		cout << ans[i] << "\n";

	return 0;
}
