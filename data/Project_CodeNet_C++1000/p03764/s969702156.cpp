#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define pi 3.141592653589793238
#define int long long
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

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

    int n,m;
    cin>>n>>m;
    int x[n+1],y[m+1];
    int ans1=0,ans2=0;
    int prev=0;
    for(int i=1;i<=n;i++)
    {
        cin>>x[i];
        ans1+=((i-1)*x[i])%mod-prev+mod;
        prev+=x[i];
        prev%=mod;
        ans1%=mod;   
    }
    prev=0;
    for(int i=1;i<=m;i++)
    {
        cin>>y[i];
        ans2+=((i-1)*y[i])%mod-prev+mod;
        prev+=y[i];
        prev%=mod;
        ans2%=mod;   
    }
    ans1*=ans2;
    ans1%=mod;
    cout<<ans1;

} 

