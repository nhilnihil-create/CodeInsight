#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,m,x[N],a[N],b[N],c[N],p[N];long long kk;
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&x[i]);
	scanf("%d%lld",&m,&kk);
	rep(i,1,n-1)a[i]=b[i]=i;
	rep(i,1,m){int y;scanf("%d",&y);swap(a[y-1],a[y]);}
	for(;kk;kk>>=1){
		if(kk&1)
		rep(i,1,n-1)b[i]=a[b[i]];
		rep(i,1,n-1)c[i]=a[a[i]];
		rep(i,1,n-1)a[i]=c[i];
	}
	long long ans=x[1];
	rep(i,1,n){
		printf("%lld.0\n",ans);
		ans+=x[b[i]+1]-x[b[i]];
	}
}