#include <bits/stdc++.h>
#define mp make_pair
#define eb emplace_back
#define fi first
#define se second
using namespace std;
using cd = complex <double>;

const long long INF = 1e18; 
const int mod = 200003;//1e9 + 7;//786433;//998244353;//1e9 + 7
const double Pi = acos(-1);
  
void Fastio()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

int h, w, H, W;

signed main()
{
	Fastio();
	cin >> H >> W >> h >> w;
	if(H % h == 0 && W % w == 0)
	{
		cout << "No";
		return 0;
	}
	cout << "Yes\n";
	if(H % h != 0)
	{
		for(int i = 1; i <= H; i++)
		{
			for(int j = 1; j <= W; j++)
			{
				if(i % h == 0)
				{
					cout << -2000 * (h - 1) - 1 << ' ';
				}
				else
				{
					cout << 2000 << ' ';
				}
			}
			cout << '\n';
		}
	}
	else
	{
		for(int i = 1; i <= H; i++)
		{
			for(int j = 1; j <= W; j++)
			{
				if(j % w == 0)
				{
					cout << -2000 * (w - 1) - 1 << ' ';
				}
				else
				{
					cout << 2000 << ' ';
				}
			}
			cout << '\n';
		}
	}
}