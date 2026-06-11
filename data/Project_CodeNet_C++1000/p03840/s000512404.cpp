//By Don4ick 
//#define _GLIBCXX_DEBUG

#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;
typedef unsigned int ui;

#define forn(i, n) for (int i = 1; i <= n; i++)
#define pb push_back
#define all(x) x.begin(), x.end()
#define y1 qewr1234

const double PI = acos(-1.0);
const int DIR = 4;
const int X[] = {1, 0, -1, 0};
const int Y[] = {0, 1, 0, -1};

using namespace std;

int main()
{
	//ios_base::sync_with_stdio(false);
	//cin.tie();
	//cout.tie();		

	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);

	ll a, b, c, d, e, f, g;
	cin >> a >> b >> c >> d >> e >> f >> g;
	ll ans = b;
	ll x = a;
	ll y = d;
	ll z = e;
	ll res = (x / 2 + y / 2 + z / 2) * 2;
	if (x > 0 && y > 0 && z > 0)
		res = max(res, 3 + 2 * ((x - 1) / 2 + (z - 1) / 2 + (y - 1) / 2));
	cout << ans + res << endl;

	return 0;
}

