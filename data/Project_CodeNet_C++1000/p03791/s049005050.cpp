#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define repp(i, m, n) for(int i = m; i < n; i++)
#define reps(i, n) for(int i = 1; i <= n; i++)
const int    INF = 100000000;
const double EPS = 1e-10;
const int    MOD = 1000000007;
using namespace std;
typedef long long ll;
typedef pair<int, int> pai;
typedef pair<ll,ll> pal;
int main()
{
	ll ans=1;
	int n, x[100010], a[100010]={};
	cin >> n;
	reps(i, n) cin >> x[i];
	repp(j, 2, n+1)
	{
		if(x[j-1]<(2*j-3))
		{
			a[1]=j-1;
			break;
		}
	}
	if(a[1]==0) a[1]=n;
	repp(k, 2, n+1)
	{
		repp(j, a[k-1], n+1)
		{
			if(x[j-1]<(2*j-3-2*(k-1)))
			{
				a[k]=j-1;
				break;
			}
		}
		if(a[k]==0) a[k]=n;
	}
	reps(i, n)
	{
		ans*=((long long)a[i]+1-i);
		ans%=MOD;
	}
	cout << ans << endl;
	return 0;
}
