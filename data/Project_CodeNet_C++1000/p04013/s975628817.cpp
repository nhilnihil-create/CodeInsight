#include<bits/stdc++.h>
using namespace std;
#define ll  long long
#define endl '\n'
#define FASTINOUT ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
ll dp[51][51][2509],a[51],x,k;
ll f(int i ,int cnt ,int sum){
    if (i==x)
        return((double)sum/cnt==k);
    if (dp[i][cnt][sum]!=-1)
        return dp[i][cnt][sum];
    return dp[i][cnt][sum]=f(i+1,cnt,sum)+f(i+1,cnt+1,sum+a[i]);
}
int main()
{
    FASTINOUT;
    cin>>x>>k;
    for (int i=0;i<x;i++)
        cin>>a[i];
    memset(dp,-1,sizeof dp);
    cout<<f(0,0,0);
    return 0;
}



