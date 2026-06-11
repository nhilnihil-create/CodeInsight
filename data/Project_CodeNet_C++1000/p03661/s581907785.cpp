#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define pi 3.141592653589793238
#define int long long
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


int pre[200005];


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
    int tot=0;
    int x;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        pre[i]=pre[i-1]+x;
        tot+=x;
    }
    int ans=1e17;
    for(int i=1;i<n;i++)
    {
        ans=min(ans,abs(tot-pre[i]*2));
    }
    cout<<ans;
} 


