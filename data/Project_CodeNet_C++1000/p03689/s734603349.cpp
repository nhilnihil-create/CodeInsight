#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define pi 3.141592653589793238
#define int long long
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// mt19937 gen_rand_int(chrono::steady_clock::now().time_since_epoch().count());
// mt19937_64 gen_rand_ll(chrono::steady_clock::now().time_since_epoch().count());
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

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

    int n,m,h,w;
    cin>>n>>m>>h>>w;
        int a[505][505];
        int z=1e9;
        z++;
        z/=max(2LL,h*w-1);
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
                a[i][j]=-z;
        }
        int tot=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(((i-1)%h==0) && ((j-1)%w==0))
                {
                    a[i][j]=(h*w-1)*z-1;
                }
                tot+=a[i][j];
            }
        }
        if(tot<=0)
        {
            cout<<"No";
            return 0;
        }
        cout<<"Yes\n";
        for(int i=1;i<=n;i++)  
        {
            for(int j=1;j<=m;j++)
                cout<<a[i][j]<<" ";
            cout<<'\n';
        }
    

} 
    
