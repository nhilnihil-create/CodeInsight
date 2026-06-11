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

const int maxn = 5e5 + 100;
const ll inf = 2e18, mod = 1e9 + 7;

int n, x[maxn], a[maxn];
bool alpha[maxn], valid = true;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> x[i], x[i]--;

	for (int i = 0; i < n; i++)
	{
		if (a[x[i]])
			valid = false;
		a[x[i]] = i + 1;
		alpha[x[i]] = true;
	}
	int pos = 0;
	for (int i = 0; i < n * n; i++)
	{
		if (a[i])
		{
			int cnt = a[i] - 1;
			while (cnt && pos <= i)
			{
				if (a[pos])
					pos++;
				else
					a[pos] = a[i], cnt--, pos++;
			}
			if (cnt)
				valid = false;
		}
	}

	pos = n * n - 1;
	for (int i = n * n - 1; i >= 0; i--)
	{
		if (alpha[i])
		{
			int cnt = n - a[i];
			while (cnt && pos >= i)
			{
				if (a[pos])
					pos--;
				else
					a[pos] = a[i], cnt--, pos--;
			}
			if (cnt)
				valid = false;
		}
	}

	if (valid)
	{
		cout << "Yes" << endl;
		for (int i = 0; i < n * n; i++)
			cout << a[i] << ' ';
		cout << endl;
	}
	else
		cout << "No" << endl;
}

