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
int pre[1000005];
int ans[1000005];
int fi[1000005];

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
    if(n==1)
    {
        cout<<1;
        return 0;
    }
    ans[1]=1;
    pre[1]=1;
    fi[1]=1;
    for(int i=2;i<=n;i++)
    {
        int tot=0;
        if(i>3)
        {
            tot+=ans[i-3];
            tot%=mod;
            tot=(pre[i-3]*(i-2))%mod-tot+mod;
            tot%=mod;
        }
        tot++;
        ans[i]=(i*tot)%mod+ans[i-1];
        ans[i]%=mod;
        pre[i]=tot+pre[i-1];
        pre[i]%=mod;
        fi[i]=tot%mod;
    }
    int res=1;
    for(int i=1;i<n;i++)
    {
        int z=fi[i]*n;
        z%=mod;
        z*=n-1;
        z%=mod;
        res+=z;
        res%=mod;
    }
    res+=(fi[n]*(n-1))%mod;
    res%=mod;
    cout<<res;

} 

