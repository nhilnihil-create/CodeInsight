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
const int maxn=500+10;
ll A[maxn][maxn];
int main(){
	int H=read(),W=read(),h=read(),w=read();
	if(H%h==0 && W%w==0) return printf("No\n"),0;
	int V=2000;
	A[0][0]=V*(h*w-1)-1;
	REP(i,0,h-1) REP(j,0,w-1) if(i || j) A[i][j]=-V;
	printf("Yes\n");
	REP(i,0,H-1) REP(j,0,W-1) printf("%d%c",A[i%h][j%w],j==jend?'\n':' ');
	return 0;
}
