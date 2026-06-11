#include<cstdio>
#include<cstring>

#define MAXN 5000
#define MOD 1000000007
int N,len;
char str[MAXN+5];
long long dp[MAXN+5][MAXN+5];

int main(){
    scanf("%d%s",&N,str+1);
    len=strlen(str+1);
    dp[0][0]=1;
    for(int i=1;i<=N;i++)
        for(int j=0;j<=N;j++){
            if(j==0) dp[i][j]+=dp[i-1][j]+dp[i-1][j+1]*2;
            else dp[i][j]+=dp[i-1][j-1]+dp[i-1][j+1]*2;
            dp[i][j]%=MOD;
        }
    printf("%lld",dp[N][len]);
}
