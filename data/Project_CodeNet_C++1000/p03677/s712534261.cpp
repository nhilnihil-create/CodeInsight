#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

#define LL long long
inline LL read(){
	LL x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
	for(;isdigit(c);c=getchar()) x=x*10+c-'0';
	return x*f;
}
const LL MAXN = 200010;
const LL INF = 2147483600;

LL N,M;
LL Ad[MAXN+1],Adx[MAXN+1];
inline LL Gd(LL x,LL y){
	if(x<y) return y-x;
	else return M-(x-y);
} inline bool kua(LL x,LL y){
	return abs(x-y)>N+1-abs(x-y);
} inline void Add(LL x,LL y,LL Fir){
	Ad[x]+=Fir; Ad[y+1]-=(Fir+(y-x)); Adx[x+1]++; Adx[y+1]--;
} LL a[MAXN+1],dist[MAXN+1],ans;

int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	N=read(),M=read();
	for(LL i=1;i<=N;i++) a[i]=read();
	for(LL i=2;i<=N;i++) dist[i]=Gd(a[i-1],a[i]);
	for(LL i=2;i<=N;i++){
		LL x=a[i-1],y=a[i];
		//if(x>y){ if(x<M) Add(x+1,M,0); Add(1,y,M-x);}
		//else { if(x<y) Add(x+1,y,0); }
		if(x<y&&y-x>=2) Add(x+2,y,1);
		if(x>y){
			if(x+2<=M) Add(x+2,M,1);
			if(M-x>=1) Add(1,y,M-x);
			else if(y>=2) Add(2,y,1);
		}
	} LL now=0,from=0;
	for(LL i=1;i<=M;i++){now+=Ad[i]; from+=Adx[i]; now+=from; ans=max(ans,now);}
	for(LL i=2;i<=N;i++) ans-=dist[i];
	printf("%lld\n",-ans);
	return 0;
}
