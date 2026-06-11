#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define pi 3.141592653589793238
#define int long long
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

long long power(long long a, long long b,long long m) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a %m;
        a = a * a %m;
        b >>= 1;
    }
    return res;
}

const int mod=998244353;


int dp[3005][3005];

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
    int a[n+2];
    int tot=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        tot+=a[i];
    }
    int z=n*(n+1)/2;
    if(tot%z)
        cout<<"NO";
    else
    {
        z=tot/z;
        int temp=z;
        int diff;
        // cout<<z<<'\n';
        a[n+1]=a[1];
        for(int i=2;i<=n+1;i++)
        {   
            diff=a[i-1]-a[i]+z;
            // cout<<diff<<'\n';
            if(diff<0)
            {
                cout<<"NO";
                return 0;
            }
            if(diff%n)
            {
                cout<<"NO";
                return 0;
            }
            // cout<<diff/n<<'\n';
            temp-=diff/n;
        }

        if(temp)
            cout<<"NO";
        else
        {
            cout<<"YES";
        }
        
    }
    


} 
    
 