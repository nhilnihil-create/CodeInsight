#include<bits/stdc++.h>
#define L long long
#define pb push_back
#define pi pair<int,int>
#define pii pair<pair<int,int>,int>
#define aa first
#define bb second
#define xx aa.aa
#define yy aa.bb
#define zz bb
#define mp make_pair
#define mpp(a,b,c) mp(mp(a,b),c)
using namespace std;
int n,m,x[200010];
L p,a[200010];
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i;
	L k;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	  scanf("%d",&x[i]);
	for(i=1;i<n;i++)
	  {
	   if(x[i+1]<x[i])
	     x[i+1]+=m;
	   p+=x[i+1]-x[i];
	   a[x[i]+2]++;
	   a[x[i+1]+1]-=x[i+1]-x[i];
	   a[x[i+1]+2]+=x[i+1]-x[i]-1;
	   x[i+1]%=m;
	  }
	for(i=1;i<=2*m;i++)
	  a[i]+=a[i-1];
	for(i=1;i<=2*m;i++)
	  a[i]+=a[i-1];
	for(i=1,k=0;i<=m;i++)
	  k=max(k,a[i]+a[i+m]);
	printf("%lld\n",p-k);
	return 0;
}
