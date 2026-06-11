#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e3+5,M=2e4+5,inf=0x3f3f3f3f,mod=1e9+7;
#define mst(a,b) memset(a,b,sizeof a)
#define lx x<<1
#define rx x<<1|1
#define reg register
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
#define il inline
int n,m;
PII a[N<<1];
int w[N<<1];
ll d[N];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&a[i].fi,&a[i].se,&w[i]);
	}
	for(int i=1;i<=n;i++) d[i]=-1e15;
	d[1]=0;
	ll d1=0,d2=0;
	for(int i=1;i<=2*n;i++){
		for(int j=1;j<=m;j++){
			d[a[j].se]=max(d[a[j].se],d[a[j].fi]+w[j]);
		}
		if(i==n) d1=d[n]; 
		if(i==2*n) d2=d[n];
	}
	if(d1!=d2) puts("inf");
	else printf("%lld\n",d1);
	return 0;
}