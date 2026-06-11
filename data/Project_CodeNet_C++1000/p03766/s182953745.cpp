#include<iostream>
#include<cstdio>
using namespace std;  
typedef long long ll;  
const ll mod=1e9+7;  
ll dp[1000003];  
int main()  
{  
    ll n,sum=0;  
    scanf("%lld",&n);  
    dp[1]=n;  
    dp[2]=(n*n)%mod;
    for(int i=3;i<=n;i++)
    {
        sum=(sum+dp[i-3])%mod;
        dp[i]=(dp[i-1]+sum+(n-1)*(n-1)+n-i+2)%mod;
    }
    printf("%lld\n",dp[n]); 
    return 0;  
}  