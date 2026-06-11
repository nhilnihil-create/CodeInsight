#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define pi 3.141592653589793238
#define int long long
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

long long power(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}


int pre[100005];

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
    int a[n+1];
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);

    int sum=a[1];
    for(int i=2;i<=n;i++)
    {
        int z=a[i]-2*sum;
        int l=1,r=n;
        int mn=n+1;
        while (l<=r)
        {
            int  mid=l+(r-l)/2;
            if(a[mid]>=z)
            {
                r=mid-1;
                mn=min(mn,mid);
            }
            else
            {
                l=mid+1;
            }            
        }
        if(z>0)
        {
            pre[1]++;
            mn=max(mn,i);
            pre[mn]--;            
        }
        sum+=a[i];
    }
    int ans=0;
    if(a[1]*2>=a[2]&& pre[1]==0)
        ans++;
    for(int i=2;i<=n;i++)
    {
        pre[i]+=pre[i-1];
        if(pre[i]==0)
        {
            ans++;
        }
    }
    cout<<ans;

} 
    
 
