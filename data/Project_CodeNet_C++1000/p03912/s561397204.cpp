#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define repp(i, m, n) for(int i = m; i < n; i++)
const int    INF = 100000000;
const double EPS = 1e-10;
const int    MOD = 1000000007;
using namespace std;
typedef long long ll;
typedef pair<int, int> pai;
typedef pair<ll,ll> pal;
int main()
{
	int n, m, x, y;
	int a[100010]={};
	int b[100010]={};
	int c[100010]={};
	cin >> n >> m;
	rep(i, n)
	{
		cin >> x;
		a[x]++;
		b[(x%m)]++;
	}
	repp(i, 1, 100010)
	{
		y=a[i]/2;
		c[(i%m)]+=y;
	}
	int ans=0;
	int t;
	if(m%2!=0)
	{
		repp(i, 1, (m/2)+1)
		{
			t=min(b[i], b[m-i]);
			b[i]-=t;
			b[m-i]-=t;
			ans+=t;
			ans+=min(b[i]/2, c[i]);
			ans+=min(b[m-i]/2, c[m-i]);
		}
		ans+=b[0]/2;
	}
	else
	{
		repp(i, 1, (m/2))
		{
			t=min(b[i], b[m-i]);
			b[i]-=t;
			b[m-i]-=t;
			ans+=t;
			ans+=min(b[i]/2, c[i]);
			ans+=min(b[m-i]/2, c[m-i]);			
		}
		ans+=b[0]/2;
		ans+=b[(m/2)]/2;
	}
	cout << ans << endl;
	return 0;
}