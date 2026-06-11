#include<bits/stdc++.h>
using namespace std;

typedef long long s64;
#define rep(i,l,r) for(int i=l;i<=r;++i)
const int N=1e5+5;
int px[N],p[N],d0[N],d1[N];

bool vis[N];
int c[N],len;
void pow_p(int n,s64 k)
{
	rep(x,1,n)
	if(!vis[x])
	{
		len=0;
		for(int y=x;!vis[y];y=p[y])vis[c[len++]=y]=1;
		int now=k%len;
		rep(i,0,len-1)d1[c[i]]=d0[c[(i+now)%len]]; 	
	}
}

int main()
{
	//freopen("1.in","r",stdin);
	int n;
	cin>>n;
	rep(i,1,n)scanf("%d",px+i);
	rep(i,1,n-1)d0[i]=px[i+1]-px[i];
	int m;s64 k;
	cin>>m>>k;
	rep(i,1,n-1)p[i]=i;
	while(m--)
	{
		int a;
		scanf("%d",&a);
		swap(p[a-1],p[a]);
	}
	pow_p(n-1,k);
	s64 ans=px[1];
	printf("%lld\n",ans);
	rep(i,1,n-1)
	{
		ans+=d1[i];
		printf("%lld\n",ans);
	}
}