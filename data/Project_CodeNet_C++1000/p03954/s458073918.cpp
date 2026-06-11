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

const int maxn = 3e5 + 100;
const ll inf = 2e18, mod = 1e9 + 7;

int n, a[maxn], b[maxn];

int solve(int val)
{
	for (int i = 0; i < 2 * n - 1; i++)
		b[i] = (a[i] >= val);
 
	int pos = n - 1;
	if (b[pos] == b[pos - 1] || b[pos] == b[pos + 1])
		return b[pos];
 
	int LEFT = pos, RIGHT = pos;
	for (int i = pos + 1; i < 2 * n - 1; i++)
	{
		if (b[i] != b[i - 1])
			RIGHT = i;
		else
			break;
	}
	for (int i = pos - 1; i >= 0; i--)
	{
		if (b[i] != b[i + 1])
			LEFT = i;
		else
			break;
 	}

	if (LEFT == 0 && RIGHT == 2 * n - 2)
		return b[0];
	if (LEFT == 0)
		return b[RIGHT];
	if (RIGHT == 2 * n - 2)
		return b[LEFT];
 
	if (b[LEFT] == b[RIGHT])
		return b[LEFT];
	if (abs(pos - LEFT) < abs(pos - RIGHT))
		return b[LEFT];
	return b[RIGHT];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < 2 * n - 1; i++)
		cin >> a[i];
	
	int l = 0, r = 2 * n, mid;
	while (r - l > 1)
	{
		mid = (l + r) / 2;
		if (solve(mid))
			l = mid;
		else
			r = mid;
	}
	cout << l << endl;
}

