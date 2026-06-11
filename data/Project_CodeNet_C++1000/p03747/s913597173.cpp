//              +-- -- --++-- +-In the name of ALLAH-+ --++-- -- --+              \\

#include <bits/stdc++.h>

#define F first
#define S second
#define _sz(x) (int)x.size()
#define pb push_back

#define error(x) cout << #x << " = " << x << endl

using namespace std ;
using ll = long long ;
using ld = long double ;
using pii = pair <int , int> ;

const int N = 1e5 + 20;
int n, l, t, x[N], w[N];
vector <int> vec;

int main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	cin >> n >> l >> t;

	int val = 0;

	for (int i = 0; i < n; i++)
	{
		cin >> x[i] >> w[i];

		if (w[i] == 1)
		{
			vec.pb((x[i] + t) % l);
			
			if (t >= l - x[i]) val += (t - (l - x[i])) / l + 1;
		}
		else 
		{
			vec.pb(((x[i] - t) % l + l) % l);	
			
			if (t > x[i]) val -= (t - x[i] - 1) / l + 1;
		}
	}

	sort(vec.begin(), vec.end());

	val = (val % n + n) % n;

	for (int i = val; i < n; i++) cout << vec[i] << '\n';
	for (int i = 0; i < val; i++) cout << vec[i] << '\n';
}
