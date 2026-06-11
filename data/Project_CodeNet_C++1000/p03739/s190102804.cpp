#include <bits/stdc++.h>
#define mp make_pair
#define eb emplace_back
#define fi first
#define se second
using namespace std;
using cd = complex <double>;
 
typedef pair <int, int> pii;
const int N = 3e3 + 5;
const long long INF = 1e18;
const int mod = 1e9 + 123;//786433;//998244353;
const double Pi = acos(-1);
const int p = 510200;
 
void Fastio()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

int n;
long long ans = 0, s = 0, ans2 = 0, s2 = 0;

signed main()
{
	Fastio();
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		long long temp;
		cin >> temp;
		s += temp;
		s2 += temp;
		if(i % 2 == 1)
		{
			if(s <= 0)
			{
				ans += abs(s) + 1;
				s = 1;
			}
		}
		else
		{
			if(s >= 0)
			{
				ans += abs(s) + 1;
				s = -1;
			}
		}
		if(i % 2 == 0)
		{
			if(s2 <= 0)
			{
				ans2 += abs(s2) + 1;
				s2 = 1;
			}
		}
		else
		{
			if(s2 >= 0)
			{
				ans2 += abs(s2) + 1;
				s2 = -1;
			}
		}
	}
	cout << min(ans, ans2);
}