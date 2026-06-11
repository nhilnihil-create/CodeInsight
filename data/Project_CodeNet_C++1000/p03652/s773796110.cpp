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

long long power(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a ;
        a = a * a ;
        b >>= 1;
    }
    return res;
}

int a[305][305];
int pos[305][305];

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
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>a[i][j];
            pos[a[i][j]][i]=j;
        }
    }    
    
    int l=1,r=n;
    int mn=1e10;
    while (l<=r)
    {
        int mid=l+(r-l)/2;
        int ind[305]={};
        int mm[305]={};
        int lol[305]={};
        int cnt[305]={};
        bool flag=true;
        while (flag)
        {
            for(int i=1;i<=n;i++)
            {
                if(lol[i]==0)
                {
                    ind[i]++;
                    
                    while (mm[a[i][ind[i]]]==1)
                    {
                        ind[i]++;
                        if(ind[i]>=m+1)
                            break;
                    }        
                    if(ind[i]>m)
                    {
                        flag=false;
                        break;
                    }
                    cnt[a[i][ind[i]]]++;
                    lol[i]=1;
                }
            }
            
            for(int i=1;i<=m;i++)
            {
                if(cnt[i]>mid)
                    mm[i]=1;
            }
            bool ok=true;
            for(int i=1;i<=n;i++)
            {
                if(mm[a[i][ind[i]]])
                {
                    ok=false;
                    lol[i]=0;
                }
            }
            if(ok)
                break;
        }

        if(flag)
        {
            mn=min(mn,mid);
            r=mid-1;
        }        
        else
        {
            l=mid+1;
        }        
    }
    cout<<mn;
    
} 
    
