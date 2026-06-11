#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
const int N=100005;
int a[N],n; 
int gcd (int x,int y)	{return x==0?y:gcd(y%x,x);}
int cnt[2];
bool solve ()
{
	cnt[0]=cnt[1]=0;
	for (int u=1;u<=n;u++) cnt[a[u]&1]++;
	if (cnt[0]&1) return true;
	if (cnt[1]>1) return false;
	int d=0;
	for (int u=1;u<=n;u++)
	{
		if (a[u]&1) 
		{
			if (a[u]==1) return false;
			a[u]--;
		}
		d=gcd(d,a[u]);
	}
	for (int u=1;u<=n;u++) a[u]/=d;
	return solve()^1;
}
int main()
{
	scanf("%d",&n);
	for (int u=1;u<=n;u++) scanf("%d",&a[u]);
	if (solve()) printf("First\n");
	else printf("Second\n");
	return 0;
}
