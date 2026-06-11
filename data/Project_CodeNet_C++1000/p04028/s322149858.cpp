#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define pi 3.141592653589793238
#define int long long
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int dp[2][5005];
const int mod=1e9+7;

signed main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);  
cout.tie(0);   

#ifndef ONLINE_JUDGE
    if(fopen("INPUT.txt","r"))
    {
    freopen ("INPUT.txt" , "r" , stdin);
    freopen ("OUTPUT.txt" , "w" , stdout);
    }
#endif  


    int n;
    cin>>n;
    string s;
    cin>>s;
    int len=s.length();
    s="#"+s;
    dp[0][0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            dp[i&1][j]=dp[(i+1)&1][j+1]*2;
            if(j>=1)
                dp[i&1][j]+=dp[(i+1)&1][j-1];
            if(j==0)
                dp[i&1][j]+=dp[(i+1)&1][j];
            dp[i&1][j]%=mod;
        }
    }
    cout<<dp[n&1][len];
} 
