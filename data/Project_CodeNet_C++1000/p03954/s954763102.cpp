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
const int maxn=2e6+10;
int a[maxn],n,b[maxn],p[maxn];
bool check(int x){
	REP(i,1,2*n-1) b[i]=(a[i]>=x);
	memset(p,0,sizeof(p));
	for(int i=1,j;i<2*n;i=j+1){
		j=i;
		while(j<2*n-1 && b[j+1]==b[i]) ++j;
		if(j>i) REP(k,i,j) p[k]=1;
	}
	if(p[n]==1) return b[n];
	int L=n,R=n;
	while(L>1 && !p[L-1]) --L;
	while(R<2*n-1 && !p[R+1]) ++R;
	if(L==1 && R==2*n-1) return (b[n]^((n-1)&1));
	if(n-L>=R-n) return b[R+1];
	return b[L-1];
}
int main(){
	n=read();
	REP(i,1,2*n-1) a[i]=read();
	int L=1,R=2*n-1;
	while(L<=R){
		int Mid=(L+R)>>1;
		if(check(Mid)) L=Mid+1;
		else R=Mid-1;
	}
	printf("%d\n",L-1);
	return 0;
}
