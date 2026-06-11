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

int n;
int a[200005], b[200005];

signed main()
{
	Fastio();
	cin >> n;
	for(int i = 1; i <= 2 * n - 1; i++)
	{
		cin >> a[i];
	}
	int l = 1, r = 2 * n - 1;
	while(l < r)
	{
		int mid = (l + r + 1) >> 1;
		int ll = 1, rr = 2 * n - 1;
		for(int i = n; i > 1; i--)
		{
			if(a[i] >= mid && a[i - 1] >= mid)
			{
				ll = i;
				break;
			}
			else if(a[i] < mid && a[i - 1] < mid)
			{
				ll = i;
				break;
			}
		}
		for(int i = n; i < 2 * n - 1; i++)
		{
			if(a[i] >= mid && a[i + 1] >= mid)
			{
				rr = i;
				break;
			}
			else if(a[i] < mid && a[i + 1] < mid)
			{
				rr = i;
				break;
			}
		}
		if(n - ll <= rr - n)
		{
			if(a[ll] >= mid)
			{
				l = mid;
			}
			else
			{
				r = mid - 1;
			}
		}
		else
		{
			if(a[rr] >= mid)
			{
				l = mid;
			}
			else
			{
				r = mid - 1;
			}
		}
	}
	cout << l;
}