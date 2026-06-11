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

int n, m, A[maxn], a[maxn], b[maxn];
vector<int> odd;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	int cnt = 0;
	for (int i = 0; i < m; i++)
	{
		cin >> A[i];
		if (A[i] & 1)
		{
			cnt++;
			odd.pb(A[i]);
		}
	}
	if (cnt > 2)
	{
		cout << "Impossible" << endl;
		return 0;
	}

	if (cnt)
	{
		a[0] = odd[0];
		if (cnt == 2)
			a[m - 1] = odd[1];
		int ind = 1;
		for (int i = 0; i < m; i++)
			if (A[i] % 2 == 0)
				a[ind++] = A[i];
	}
	else
		swap(a, A);
	
	int ind = 0;
	if (n == 1)
		b[ind++] = n;
	else if (m == 1)
	{
		ind = 2;
		b[0] = n - 1;
		b[1] = 1;
	}
	else
	{
		b[ind++] = a[0] + 1;
		for (int i = 1; i < m - 1; i++)
			b[ind++] = a[i];
		if (a[m - 1] > 1)
			b[ind++] = a[m - 1] - 1;
	}

	for (int i = 0; i < m; i++)
		cout << a[i] << ' ';
	cout << endl << ind << endl;
	for (int i = 0; i < ind; i++)
		cout << b[i] << ' ';
	cout << endl;
}

