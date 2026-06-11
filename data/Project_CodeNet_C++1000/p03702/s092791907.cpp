#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define pi 3.141592653589793238
#define int long long
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


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

    int n,a,b;
    cin>>n>>a>>b;
    int hlt[n+1];
    for(int i=1;i<=n;i++)
            cin>>hlt[i];
    int l=1,r=1e9;
    int z=(a-b);
    int ans=1e9;
    while(l<=r)
    {
        int mid=l+(r-l)/2;
        int tot=0;
        for(int i=1;i<=n;i++)
        {
            int temp=hlt[i];
            temp-=mid*b;
            if(temp>0)
            {
                tot+=(temp/z);
                if(temp%z)
                    tot++;
            }
        }
        if(tot<=mid)
        {
            ans=min(ans,mid);
            r=mid-1;
        }
        else
        {
            l=mid+1;
        }
    }
    cout<<ans;

} 

