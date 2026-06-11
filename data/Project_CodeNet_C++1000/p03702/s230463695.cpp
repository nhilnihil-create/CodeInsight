# include<bits/stdc++.h>
 
using namespace std;
 
# define int long long
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, int> pdi;
typedef pair<ll, ll> pll;
 
# define S second
# define F first
# define kill(x) return(cout << x << endl, 0LL)
# define debug(x) cerr<< #x << " = " << x << endl
# define ddebug(x, y) cerr<< #x << " = " << x  << ", " << #y << " = " << y << endl
# define tdebug(x, y, z) cerr<< #x << " = " << x  << ", " << #y << " = " << y << ", " << #z << " = " << z << endl
# define sz(s) (int)s.size()
# define sq(x) (x) * (x)
# define PB(x) push_back(x)
# define smax(x, y) (x) = max((x), (y))
# define smin(x, y) (x) = min((x), (y))
# define all(x) x.begin(), x.end()
# define SP fixed << setprecision(10)
# define MP make_pair
# define uop(x, y) pii(min(x, y), max(x, y))
 
const int MAXN = 100 * 1000 + 10;
int n, a, b, 
    h[MAXN];

bool check(int x)
{
	int cnt = 0;
	for (int i = 0; i < n; i ++)
		cnt += max(0LL, ((h[i] - x * b) + a - 1) / a);
	return cnt <= x;
}

int32_t main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> a >> b;
	for (int i = 0; i < n; i ++)
		cin >> h[i];
	a -= b;

	int l = 0, r = (1e18 + 10) / b;
	while (r - l > 1)
	{
		int mid = (l + r) / 2;
		if (check(mid))
			r = mid;
		else
			l = mid;
	}
	cout << r << endl;
	

	return 0;
}
 

