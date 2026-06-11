#include<cstdio>
#include<cstring>
#include<algorithm>
#define LL long long
using namespace std;
const int mod=1e9+7,M=5e3+7;
LL read(){
	LL ans=0,f=1,c=getchar();
	while(c<'0'||c>'9'){if(c=='-') f=-1; c=getchar();}
	while(c>='0'&&c<='9'){ans=ans*10+(c-'0'); c=getchar();}
	return ans*f;
}
LL qmod(LL a,LL b){
	LL ans=1;
	while(b){
		if(b&1) ans=ans*a%mod;
		a=a*a%mod; b>>=1;
	}
	return ans;
}
LL n,m,dp[M][M];
char s[M];
int main(){
	n=read();
	scanf("%s",s+1);
	m=strlen(s+1);
	dp[0][0]=1;
	for(int i=0;i<=n;i++){
		for(int j=0;j<=i;j++){
			dp[i+1][j+1]=(dp[i+1][j+1]+2*dp[i][j]%mod)%mod;
			dp[i+1][max(j-1,0)]=(dp[i+1][max(j-1,0)]+dp[i][j])%mod;
		}	
	}
	LL ans=dp[n][m]*qmod(qmod(2,m),mod-2)%mod;
	printf("%lld\n",ans);
	return 0;
}