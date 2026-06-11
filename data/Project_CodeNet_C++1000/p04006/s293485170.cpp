#include <bits/stdc++.h>
#define mp make_pair
#define eb emplace_back
#define fi first
#define se second
#define int long long
using namespace std;
using cd = complex <double>;

typedef pair <int, int> pii;
const int N = 3e3 + 5;
const long long INF = 1e18;
const int mod = 998244353;//786433;//998244353;
const double Pi = acos(-1);

 
void Fastio()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

int n;
long long a[6005], b[2005][2005];
long long ans = 0, x = 0;



signed main()
{
	cin >> n >> x;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		ans += a[i];
		b[i][0] = a[i];
	}
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			b[i][j] = 1e9 + 8;
		}
	}
	for(int i = 1; i <= n - 1; i++)
	{
		for(int j = n; j >= 1; j--)
		{
			int temp = (j - i + n) % n;
			if(temp == 0)
			{
				temp += n;
			}
			b[j][i] = min(b[j][i - 1], a[temp]);
		}
	}
	for(int i = 0; i < n; i++)
	{
		long long temp = i * x;
		for(int j = n; j >= 1; j--)
		{
			temp += b[j][i];
		}
		ans = min(ans, temp);
	}
	cout << ans;
}