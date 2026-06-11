//              +-- -- --++-- +-In the name of ALLAH-+ --++-- -- --+              \\

#include <bits/stdc++.h>

#define int ll

#define F first
#define S second
#define _sz(x) (int)x.size()
#define pb push_back

#define error(x) cout << #x << " = " << x << endl

using namespace std ;
using ll = long long ;
using ld = long double ;
using pii = pair <int , int> ;

const int C = 100 + 10;
int n, a[C], dp[C], sum;

int32_t main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	cin >> n;

	if (n <= 100)
	{
		cout << 2 * n << '\n';
		for (int i = 0; i < n; i++) cout << i + 1 << ' ';
		for (int i = 0; i < n; i++) cout << n - i << ' ';
		cout << '\n';
		return 0;
	}


	sum = 100;

	for (int i = 0; i < 100; i ++)
	{
		dp[i] = 1;

		vector <pii> vec;

		for (int j = 0; j < i; j++) vec.pb({a[j], dp[j]});

		sort(vec.begin(), vec.end());

		int p = 1;
		for (int j = 0; j < i; j++)
		{
			if (sum + vec[j].S > n) break;
			p++;
			dp[i] += vec[j].S;
			sum += vec[j].S;
		}

		a[i] = p;
		for (int j = 0; j < i; j++)
			if (a[j] >= p) a[j]++;
	}

	cout << "200\n";
	for (int i = 0; i < 100; i++) cout << i + 1 << ' ';
	for (int i = 0; i < 100; i++) cout << a[i] << ' ';
	cout << '\n';
}
