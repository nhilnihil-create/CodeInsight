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
const int maxn=100+10;
int a[maxn],l,r;
int Ans[maxn],tmp;
int main(){
	int n=read(),m=read(),num=0;
	REP(i,1,m){
		a[i]=read();
		if(a[i]&1){
			if(l) r=a[i];
			else l=a[i];
			++num;
		}
	}
	if(num>2) return printf("Impossible\n"),0;
	if(l) Ans[++tmp]=l;
	REP(i,1,m) if(a[i]%2==0) Ans[++tmp]=a[i];
	if(r) Ans[++tmp]=r;
	REP(i,1,tmp) printf("%d%c",Ans[i],i==iend?'\n':' ');
	Ans[1]--;
	if(tmp==1) ++tmp;
	Ans[tmp]++;
	printf("%d\n",tmp-(Ans[1]==0));
	REP(i,1,tmp) if(Ans[i]!=0) printf("%d%c",Ans[i],i==iend?'\n':' ');
	return 0;
}
