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

const int MAXN = 100 * 1000 + 10;
int n, a[2 * MAXN],
    mini;

bool b(int y)
{
	return (a[y] >= mini);
}

bool good()
{
	for (int i = 0; i < n; i ++)
	{
		if (b(n - 1 - i) == b(n - 1 - i - 1))
			return b(n - 1 - i);
		if (b(n - 1 + i) == b(n - 1 + i + 1))
			return b(n - 1 + i);
	}
	return b(n - 1) ^ (n & 1 ^ 1);
}

int bs()
{
	int l = 0, r = 2 * n + 1;
	while (r - l > 1)
	{
		int mid = (r + l) / 2;
		mini = mid;
		if (good())
			l = mid;
		else
			r = mid;
	}
	return l;
}

int32_t main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < 2 * n - 1; i ++)
		cin >> a[i];

	cout << bs() << endl;

	return 0;
}
