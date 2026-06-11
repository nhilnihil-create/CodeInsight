#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define mp make_pair
#define REP(i,j,k)  for(int i=(j);i<=(k);++i)
#define REPD(i,j,k) for(int i=(j);i>=(k);--i)

const int maxn = 1e5+10;
long long a[maxn],sum[maxn],abssum[maxn];
int xs[maxn],nxt[maxn];
int n;

void init()
{
	char op[5];
	cin>>n>>a[1];
	sum[1]=abssum[1]=a[1];
	REP(i,2,n)
	{
		cin>>op>>a[i];
		if(op[0]=='-') xs[i]=-1;
		else xs[i]=1;
		abssum[i]=abssum[i-1]+a[i];
		sum[i]=sum[i-1]+xs[i]*a[i];
	}
	nxt[n]=n;
	REPD(i,n-1,2)
		if(xs[i+1]==-1) nxt[i]=i;
		else nxt[i]=nxt[i+1];
}

void solve()
{
	long long ans=sum[n];
	REP(i,2,n)
		if(xs[i]==-1)
			ans=max(ans,sum[i-1]-(abssum[nxt[i]]-abssum[i-1])+abssum[n]-abssum[nxt[i]]);
	cout<<ans<<endl;
}

int main()
{
	init();
	solve();
	
	return 0;
}