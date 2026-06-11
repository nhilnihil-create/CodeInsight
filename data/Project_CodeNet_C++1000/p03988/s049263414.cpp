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

multiset <int> ms;

int32_t main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	int x = 0;
	for (int i = 0; i < n; i ++)
	{
		int a;
		cin >> a;
		smax(x, a);
		ms.insert(a);
	}

	for (int i = 0; i < 2; i ++)
		if (ms.find(x) == ms.end())
			kill("Impossible");
		else
			ms.erase(ms.find(x));

	
	for (int i = 1; i <= x - 1; i ++)
	{
		int a = max(i, x - i);
		if (ms.find(a) == ms.end())
			kill("Impossible");
		else
			ms.erase(ms.find(a));
	}


	for (int a : ms)
		if (a < (x + 1) / 2 + 1)
			kill("Impossible");

	cout << "Possible" << endl;

	return 0;
}
 

