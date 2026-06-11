#include<iostream>
#include<cstdio>
#include<cstring>
typedef long long lint;
const int N=1e5+2;
int n,hx[N];
lint dp[N][3];

template <class T> inline void apx(T &x,const T y){
	if(x<y) x=y;
}

inline int nxi(){
	int x=0;
	char c;
	while((c=getchar())>'9'||c<'0');
	while(x=x*10-48+c,(c=getchar())>='0'&&c<='9');
	return x;
}

int main(){
#ifndef ONLINE_JUDGE
//	freopen("b.in","r",stdin);
#endif
	memset(dp,-3,sizeof(dp));
	n=nxi();
	hx[1]=nxi();
	for(int i=2;i<=n;++i){
		char c;
		while((c=getchar())!='+'&&c!='-');
		hx[i]=nxi();
		if(c=='-') hx[i]=-hx[i];
	}
	dp[0][0]=0;
	for(int i=0;i<n;++i){
		apx(dp[i][1],dp[i][2]);
		apx(dp[i][0],dp[i][1]);
		for(int j=0;j<=2;++j){
			if(dp[i][j]<-1e16) continue;
			const lint tp=dp[i][j]+(j&1?-hx[i+1]:hx[i+1]);
			apx(dp[i+1][j],tp);
			if(hx[i+1]<0&&j<2){
				apx(dp[i+1][j+1],tp);
			}
		}
	}
//	for(int i=0;i<=n;++i){
//		for(int j=0;j<3;++j){
//			printf("%lld ",dp[i][j]);
//		}
//		puts("");
//	}
	lint ans=-1e16;
	for(int i=0;i<3;++i){
		apx(ans,dp[n][i]);
	}
	printf("%lld\n",ans);
	return 0;
}