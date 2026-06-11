#include <bits/stdc++.h>
#define mp make_pair
#define eb emplace_back
#define fi first
#define se second
using namespace std;
using cd = complex <double>;

const long long INF = 1e18; 
const int mod = 1e9 + 7;//200003;786433;998244353;
const double Pi = acos(-1);
  
void Fastio()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

int n, x, p;
int a[200005];

signed main()
{
	Fastio();
	cin >> n >> x;
	if(x == 1 || x == 2 * n - 1)
	{
		cout << "No";
		return 0;
	}
	cout << "Yes\n";
	if(x == 2)
	{
		if(n == 2)
		{
			cout << 1 << endl << 2 << endl << 3 << endl;
			return 0;
		}
		a[n - 1] = 4;
		a[n] = 2;
		a[n + 1] = 1;
		a[n + 2] = 3;
		p = 5;
		for(int i = 1; i <= 2 * n - 1; i++)
		{
			if(a[i] == 0)
			{
				a[i] = p;
				p++;
			}
		}
	}
	else
	{
		a[n - 1] = x - 1;
		a[n] = x;
		a[n + 1] = x + 1;
		a[n + 2] = x - 2;
		int p = 1;
		for(int i = 1; i <= 2 * n - 1; i++)
		{
			while(x - 2 <= p && p <= x + 1)
			{
				p++;
			}
			if(a[i] == 0)
			{
				a[i] = p;
				p++;
			}
		}
	}
	for(int i = 1; i <= 2 * n - 1; i++)
	{
		cout << a[i] << '\n';
	}
}