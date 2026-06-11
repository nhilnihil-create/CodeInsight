#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define fo(i,j,k) for(int i=j;i<=k;++i)
#define fd(i,j,k) for(int i=j;i>=k;--i)
#define ll long long
using namespace std;
const int N=1e5+10;
int p[N],q[N];
ll a[N],an[N];
bool vis[N];
int z[N];
int main()
{
	int n;
	scanf("%d",&n);
	fo(i,1,n) scanf("%lld",&a[i]);
	fd(i,n,1) a[i]-=a[i-1],p[i]=i;
	int m;
	ll k;
	scanf("%d %lld",&m,&k);
	while(m--){
		int x;
		scanf("%d",&x);
		swap(p[x],p[x+1]);
	}
	fo(i,1,n) if(!vis[i]){
		z[0]=0;
		for(int j=i;!vis[j];j=p[j]) z[++z[0]]=j,vis[j]=1;
		int t=1-k%z[0];
		t<=0?t+=z[0]:t;
		fo(i,1,z[0]) q[z[i]]=z[t],t=t%z[0]+1;
	}
	fo(i,1,n) an[q[i]]=a[i];
	fo(i,1,n) an[i]+=an[i-1],printf("%lld.0\n",an[i]);
}
