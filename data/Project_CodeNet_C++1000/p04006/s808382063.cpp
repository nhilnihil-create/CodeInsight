#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define pi 3.141592653589793238
#define int long long
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int mn[2005];

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

    int n,x;
    cin>>n>>x;
    int a[2*n+1];
    int tot=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        a[n+i]=a[i];
        mn[i]=a[i];
        tot+=a[i];
    }

    for(int i=1;i<=n;i++)
    {
        int sum=0;
        for(int j=1+n;j<=2*n;j++)
        {
            mn[j-n]=min(mn[j-n],a[j-i]);
            sum+=mn[j-n];
        }
        tot=min(tot,sum+i*x);
    }
    cout<<tot;

} 
