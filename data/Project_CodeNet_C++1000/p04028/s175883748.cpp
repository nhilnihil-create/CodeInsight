#include<set>  
#include<map>  
#include<stack>  
#include<cmath>  
#include<cstdio>  
#include<queue>  
#include<vector>  
#include<cstring> 
#include<climits>  
#include<iostream> 
#include<algorithm> 
using namespace std; 
int read(){ 
    int f=1,x=0; 
    char c=getchar(); 
    while(c<'0'||'9'<c){if(c=='-')f=-1;c=getchar();} 
    while('0'<=c&&c<='9'){x=x*10+c-'0';c=getchar();} 
    return f*x; 
}
#define MAXN 5000
#define MOD int(1e9+7)
#define LL long long
#define INF 0x3f3f3f3f
char str[MAXN+5];
LL dp[MAXN+5][MAXN+5];
LL QuPow(LL x,LL y){
	LL ret=1;
	while(y){
		if(y&1) ret=ret*x%MOD;
		x=x*x%MOD;
		y>>=1;
	}
	return ret;
}
int main(){//前i次操作后长度为字符长度为j的方案数
	LL ans=0;
	int n=read(),len;
	scanf("%s",str);
	len=strlen(str);
	dp[0][0]=1;
	for(int i=0;i<=n;i++)
		for(int j=0;j<=i;j++){
			dp[i+1][j+1]=(dp[i+1][j+1]+2*dp[i][j])%MOD;
			dp[i+1][max(j-1,0)]=(dp[i+1][max(j-1,0)]+dp[i][j])%MOD;
		}
	printf("%lld\n",QuPow(QuPow(2,len)%MOD,MOD-2)*dp[n][len]%MOD);
    return 0;
}