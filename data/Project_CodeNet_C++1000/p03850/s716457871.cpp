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
const int maxn=1e5+10;
ll dp[maxn][3];
char ty[10];
int main(){
	int n=read();
	REP(i,1,n) dp[i][0]=dp[i][1]=dp[i][2]=-1e18;
	dp[1][0]=read();
	REP(i,1,n-1){
		scanf("%s",ty+1);
		int x=read();
		if(ty[1]=='-') x*=-1;
		chkmax(dp[i+1][0],dp[i][0]+x);
		chkmax(dp[i+1][1],dp[i][1]-x);
		chkmax(dp[i+1][2],dp[i][2]+x);
		if(ty[1]=='-'){
			chkmax(dp[i+1][1],dp[i][0]+x);
			chkmax(dp[i+1][2],dp[i][1]-x);
		}
		chkmax(dp[i+1][0],dp[i][1]-x);
		chkmax(dp[i+1][1],dp[i][2]+x);
		chkmax(dp[i+1][0],dp[i][2]+x);
	}
	printf("%lld\n",dp[n][0]);
	return 0;
}
