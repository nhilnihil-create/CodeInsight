#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5+4;
vector <int> v;
int a[N];
int mx[N][25];
int len;
int n;
int jump(int x, int y)
{
	int ans = 0;
	for(int i=19;i>=0;i--)
	{
		if(mx[x][i] < y)
		{
			x = mx[x][i];
			ans += (1<<i);
		}
	}
 
	return ans+1;
}
 
signed main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	cin>>len;
 
	for(int i=1;i<=n;i++)
	{
		mx[i][0] = lower_bound(a+1, a+1+n, a[i] + len + 1) - (a+1);
		// cout<<mx[i][0]<<'\n';
	}
 
 
	for(int j=1;j<=19;j++)
	{
		for(int i=1;i<=n;i++)
		{
			mx[i][j] = mx[mx[i][j-1]][j-1];
		}
	}
 
	int q;
	cin>>q;
	while(q--)
	{
		int i,j;
		scanf("%lld %lld",&i,&j);
		if(i > j)
			swap(i,j);
 
		cout<<jump(i,j)<<'\n';
	}
}