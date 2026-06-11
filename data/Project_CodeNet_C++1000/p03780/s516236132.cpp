#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define pi 3.141592653589793238
// #define int long long
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int dpp[5005][5005];
int dps[5005][5005];
int ans=0;
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

    int n,k;
    cin>>n>>k;
    int a[n+1];
    for(int i=1;i<=n;i++)
        cin>>a[i];
    dpp[0][0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=k;j++)
        {
            if(j-a[i]>=0)
                dpp[i][j]|=dpp[i-1][j-a[i]];
            dpp[i][j]|=dpp[i-1][j];
        }
    }

    dps[n+1][0]=1;
    for(int i=n;i>=1;i--)
    {
        for(int j=0;j<=k;j++)
        {
            if(j-a[i]>=0)
                dps[i][j]|=dps[i+1][j-a[i]];
            dps[i][j]|=dps[i+1][j];
        }
    }

    for(int i=1;i<=n;i++)
    {
        int z=a[i];
        int x=k,y=0;
        int tt=k-a[i];
        int mn=1e9;

        while (x>=0&&y<=k)
        {
            while (x>=0&&dpp[i-1][x]==0)
            {
                x--;
            }
            while (y<tt-x && y<=k)
            {
                y++;
            }
            while (dps[i+1][y]==0 && y<=k)
            {
                y++;
            }
            if(x>=0)
            if(x+y>=tt &&(dpp[i-1][x]&dps[i+1][y]))
            {
                mn=min(mn,x+y);
            }            
            x--;
        }        
        if(mn<k)
            ans++;
    }

    cout<<n-ans;
} 

