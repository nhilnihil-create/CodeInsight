#include <iostream>
 
#include <map>
#include <unordered_map>
#include <algorithm>
#include <vector>
 
#define int long long
 
using namespace std;
//const char a[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
const int maxN=50;
int dp[maxN+1][maxN+1][maxN*maxN+1];
 
void solver() {
    
    int n,p;
    cin>>n>>p;
    int arr[maxN];
    
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    for(int i=0;i<=n;i++)
    {
        dp[i][0][0]=1;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            for(int k=0;k<=maxN*maxN;k++)
            {
                if(k<arr[i-1])
                {
                    dp[i][j][k]=dp[i-1][j][k];
                    continue;
                }
                dp[i][j][k]=dp[i-1][j-1][k-arr[i-1]]+dp[i-1][j][k];
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        ans+=dp[n][i][p*i];
    }
    cout<<ans;
    
}
 
 
int32_t main() {
    int n=1;
    //cin>>n;
    while(n--)
    {
        solver();
    }
}