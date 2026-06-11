#include<bits/stdc++.h>
#include<tr1/unordered_map>
#define CLR(a,x) memset(a,x,sizeof(a))
#define MP make_pair
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pa;
const int maxn=1e5+10;

inline ll rd(){
    ll x=0;char c=getchar();int neg=1;
    while(c<'0'||c>'9'){if(c=='-') neg=-1;c=getchar();}
    while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
    return x*neg;
}

int L,N,x[maxn],dir[maxn],y[maxn],rnk[maxn],T,ans[maxn];

inline bool cmp(int a,int b){return x[a]<x[b];}

int main(){
    //freopen("","r",stdin);
	N=rd(),L=rd(),T=rd();
	for(int i=1;i<=N;i++) x[i]=rd(),dir[i]=(rd()==1?1:-1),rnk[i]=i;
	sort(rnk+1,rnk+N+1,cmp);
	ll p=0;
	for(int i=1;i<=N;i++){
		y[i]=((x[i]+T*dir[i])%L+L)%L;
		if(dir[i]==1) p+=ceil(1.0*(T-(L-x[i])+1)/L);
		else p-=ceil(1.0*(T-x[i])/L);
		// printf(":%d\n",p);
	}
	p=(p%N+N)%N;
	sort(y+1,y+N+1);
	for(int i=p+1;i<=N;i++) ans[rnk[i-p]]=y[i];
	for(int i=1;i<=p;i++) ans[rnk[N+i-p]]=y[i];
	for(int i=1;i<=N;i++) printf("%d\n",ans[i]);
    return 0;
}