#include<bits/stdc++.h>
using namespace std;
#define REP(i,st,ed) for(register int i=st,i##end=ed;i<=i##end;++i)
#define DREP(i,st,ed) for(register int i=st,i##end=ed;i>=i##end;--i)
typedef long long ll;
template<typename T>inline bool chkmin(T &x,T y){return (y<x)?(x=y,1):0;}
template<typename T>inline bool chkmax(T &x,T y){return (y>x)?(x=y,1):0;}
inline int read(){
	int x;
	char c;
	int f=1;
	while((c=getchar())!='-' && (c>'9' || c<'0'));
	if(c=='-') f=-1,c=getchar();
	x=c^'0';
	while((c=getchar())>='0' && c<='9') x=(x<<1)+(x<<3)+(c^'0');
	return x*f;
}
inline ll readll(){
	ll x;
	char c;
	int f=1;
	while((c=getchar())!='-' && (c>'9' || c<'0'));
	if(c=='-') f=-1,c=getchar();
	x=c^'0';
	while((c=getchar())>='0' && c<='9') x=(x<<1ll)+(x<<3ll)+(c^'0');
	return x*f;
}
const int maxn=2e5+10;
int a[maxn];
ll sum1[maxn],sum2[maxn],sum;
int main(){
	int n=read(),m=read();
	REP(i,1,n) a[i]=read();
	REP(i,2,n){
		if(a[i]==a[i-1]) continue;
		if(a[i]>a[i-1]){
			sum1[a[i-1]+2]++,sum1[a[i]+1]--;
			sum2[a[i]+1]-=a[i]-a[i-1]-1;
			sum+=a[i]-a[i-1];
		}
		else{
			a[i]+=m;
			sum1[a[i-1]+2]++,sum1[a[i]+1]--;
			sum2[a[i]+1]-=a[i]-a[i-1]-1;
			sum+=a[i]-a[i-1];
			a[i]-=m;
		}
	}
	ll ans=0;
	REP(i,1,2*m){
		sum1[i]+=sum1[i-1];
		sum2[i]+=sum1[i]+sum2[i-1];
	}
	REP(i,1,m) chkmax(ans,sum2[i]+sum2[i+m]);
	printf("%lld\n",sum-ans);
	return 0;
}
