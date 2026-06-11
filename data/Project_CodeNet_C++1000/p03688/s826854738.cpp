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
int a[MAXN];

int32_t main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i ++)
		cin >> a[i];
	sort(a, a + n);
	if (a[n - 1] - a[0] > 1)
		kill("No");

	int k = 0;
	while (k < n && a[k] == a[0])
		k ++;

	if (k == n)
	{
		cout << ((a[0] + 1 == n || a[0] <= n / 2) ? "Yes" : "No") << "\n";
		return 0;
	}

	int col = a[0] + 1;
	cout << ((col > k && col - k <= (n - k) / 2) ? "Yes" : "No") << "\n";

	return 0;
}




