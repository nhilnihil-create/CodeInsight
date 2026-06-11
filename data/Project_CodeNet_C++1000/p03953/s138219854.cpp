#include<bits/stdc++.h>
#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define F2(i,a,b) for(int i=(a);i<(b);++i)
#define dF(i,a,b) for(int i=(a);i>=(b);--i)
#define dF2(i,a,b) for(int i=(a);i>(b);--i)
#define dF3(i,a,b) for(int i=(a)-1;i>=(b);--i)
using namespace std;typedef long long ll;typedef double ld;int INF=0x3f3f3f3f;int INF2=0x7fffffff;ll LNF=0x3f3f3f3f3f3f3f3f;ll LNF2=0x7fffffffffffffff;

int n,m,y;
ll k;
ll x[100001],a[100001];
ll s[100001],ans[100001],tmp[100001];

int main(){
	scanf("%d",&n);
	F(i,1,n) scanf("%lld",x+i), s[i]=i, ans[i]=i;
	dF(i,n,1) x[i]-=x[i-1];
	scanf("%d%lld",&m,&k);
	F(i,1,m) scanf("%d",&y), swap(s[y],s[y+1]);
	while(k){
		if(k&1)
			F(i,1,n) ans[i]=s[ans[i]];
		F(i,1,n) tmp[i]=s[s[i]];
		F(i,1,n) s[i]=tmp[i];
		k>>=1;
	}
	F(i,1,n) tmp[i]=x[ans[i]];
	F(i,1,n) x[i]=tmp[i];
	F(i,1,n) x[i]+=x[i-1];
	F(i,1,n) printf("%lld.0\n",x[i]);
	return 0;
}