#include <bits/stdc++.h>
#define pi 3.14159
using namespace std;
typedef long long LL;
const LL MOD = 1e9 + 7;
const int N = 1e5 + 7, M = 1e7, OO = 0x3f3f3f3f;
#define AC ios::sync_with_stdio(0);cin.tie(0);cout.tie(0); cin.sync_with_stdio(0);
int dp[100][10000],array1[105],n;
int solve(int i,int sum){
    if(i==n){
        if(sum%10==0){
            return 0;
        }
        return sum;
    }
    if(dp[i][sum]!=-1){
        return dp[i][sum];
    }
    return dp[i][sum]=max(solve(i+1,sum+array1[i]),solve(i+1,sum));
}
int main()
{
memset(dp,-1,sizeof(dp));
scanf("%d",&n);
int i;
for(i=0;i<n;++i){
    scanf("%d",&array1[i]);
}
printf("%d",solve(0,0));



    return 0;
}
