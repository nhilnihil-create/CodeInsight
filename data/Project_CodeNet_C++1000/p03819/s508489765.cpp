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
const int maxn=3e5+10;
int n,m;
struct point{
	int l,r;
}a[maxn];
struct szsz{
	int c[maxn];
	inline int lowbit(int x){
		return x&(-x);
	}
	inline int sum(int x){
		int res=0;
		while(x){
			res+=c[x];
			x-=lowbit(x);
		}
		return res;
	}
	inline void add(int x,int y){
		while(x<=n){
			c[x]+=y;
			x+=lowbit(x);
		}
	}
}bit;
vector<int> ve[maxn];
int main(){
	m=read(),n=read();
	int tag=m;
	REP(i,1,m){
		a[i].l=read(),a[i].r=read();
		if(a[i].l!=0) ve[a[i].r-a[i].l+1].push_back(i);
	}
	REP(i,1,n){
		int ans=0;
		REP(j,1,n/i) ans+=bit.sum(i*j);
		printf("%d\n",tag+ans);
		for(auto v:ve[i]) bit.add(a[v].l,1),bit.add(a[v].r+1,-1),--tag;
	}
	return 0;
}
