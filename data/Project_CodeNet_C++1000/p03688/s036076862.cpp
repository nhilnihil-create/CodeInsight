//              +-- -- --++-- +-In the name of ALLAH-+ --++-- -- --+              \\

#include <bits/stdc++.h>

#define F first
#define S second
#define _sz(x) (int)x.size()
#define pb push_back

#define error(x) cout << #x << " = " << x << endl

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;

const int N = 1e5 + 20;
int n, a[N], num, cnt;

inline void no ()
{
	cout << "No\n";
	exit(0);
}

inline void yes ()
{
	cout << "Yes\n";
	exit(0);
}

void check_n ()
{
	bool fl = 1;
	for (int i = 0; i < n; i++)
		fl &= (a[i] == n - 1);

	if (fl) yes();
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];

	check_n();

	for (int i = 0; i < n; i++)
		num = max(num, a[i]);

	if (num >= n) no();

	for (int i = 0; i < n; i++)
		if (num - a[i] > 1) no();

	for (int i = 0; i < n; i++)
		cnt += (a[i] == num - 1);

	if (cnt >= num || (n - cnt) < 2 * (num - cnt)) no();

	yes();
}
