#include <bits/stdc++.h>
#define upd(x,y) x=(x+(y)>=mu?x+(y)-mu:x+(y))
const int mu=1000000007,N=2005;
int dp[N][N],p[N*N],inv[N*N],n,k;
int ksm(int x,int y){
	int ans=1;
	for (;y;y>>=1,x=1ll*x*x%mu)
		if (y&1) ans=ans*1ll*x%mu;
	return ans;
}
int C(int x,int y){
	return 1ll*p[x]*inv[y]%mu*inv[x-y]%mu;
}
int main(){
	scanf("%d%d",&n,&k);
	if (k==1){
		puts("1");
		return 0;
	}
	int tot=n*k;
	dp[0][0]=1;
	p[0]=1;
	for (int i=1;i<=tot;i++) p[i]=1ll*p[i-1]*i%mu;
	inv[tot]=ksm(p[tot],mu-2);
	for (int i=tot;i;i--) inv[i-1]=inv[i]*1ll*i%mu;
	for (int i=0;i<=n;i++){//放了几个0 
		for (int j=i;j>=0;j--){//几个颜色没放完 
			upd(dp[i+1][j+1],dp[i][j]);//放一个0
			if(j) upd(dp[i][j-1],1ll*dp[i][j]*(n-(i-j))%mu*C((n-i)*k+j*(k-1)-1,k-2)%mu);//放一个颜色的第一个 
		}
	}
	printf("%d\n",dp[n][0]%mu);
}