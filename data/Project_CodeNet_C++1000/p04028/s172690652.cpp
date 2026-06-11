#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
typedef long long ll;
#define M 1000000007
ll n,m,ans;
char s[5005];
ll dp[5005][5005];
int main(void){
    cin>>n>>s;
    m=strlen(s);
    dp[0][m]=1;
    for(int i=0;i<n;i++){
        dp[i+1][0]=(dp[i+1][0]+dp[i][0])%M;
        for(int j=0;j<=n;j++){
            if(j>0)dp[i+1][j-1]=(dp[i+1][j-1]+dp[i][j])%M;
            dp[i+1][j+1]=(dp[i+1][j+1]+dp[i][j]*2)%M;
        }
    }
    cout<<dp[n][0]<<endl;
}