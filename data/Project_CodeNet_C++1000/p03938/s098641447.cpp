#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define mp make_pair
#define ff first
#define ss second
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define all(v) v.begin(),v.end()

const int maxn = 1e5 + 100;
const ll inf = 2e18, mod = 1e9 + 7;

int n, a[maxn], b[maxn], p[maxn], q[maxn];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> p[i], p[i]--, q[p[i]] = i;
	for (int i = 0; i < n; i++)
		a[i] = 30000 * (i + 1);
	for (int i = 0; i < n; i++)
		b[i] = 30000 * (n - i) + q[i] + 1;
	for (int i = 0; i < n; i++)
		cout << a[i] << ' ';
	cout << endl;
	for (int i = 0; i < n; i++)
		cout << b[i] << ' ';
	cout << endl;
}

