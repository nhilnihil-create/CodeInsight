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
const LL MAXN = 100010;
const LL INF = 2147483600;

LL N;
LL opr[MAXN+1];
LL a[MAXN+1],f[MAXN+1][5];

inline LL fan(LL x,LL c){
	if(c&1) return -x; return x;
}

int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	N=read(); 
	for(LL i=1;i<=N;i++){
		a[i]=read(); char c;
		if(i<N){
			c=getchar();
			getchar();
			opr[i+1]=(c=='+'?1:-1);
		}
	} memset(f,-127,sizeof(f));
	opr[1]=1; f[0][0]=0;
	for(LL i=1;i<=N;i++){
		for(LL j=0;j<=min(N,4LL);j++){
			if(j>0&&opr[i]==-1) f[i][j]=f[i-1][j-1]+fan(opr[i],j-1)*a[i];
			if(j<4&&j<N) f[i][j]=max(f[i][j],f[i-1][j+1]+fan(opr[i],j+1)*a[i]);
			f[i][j]=max(f[i][j],f[i-1][j]+fan(opr[i],j)*a[i]);
		}
	}
	for(LL i=0;i<=4LL;i++) f[N][0]=max(f[N][0],f[N][i]);
	printf("%lld\n",f[N][0]);
	return 0;
}
