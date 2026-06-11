#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define pi 3.141592653589793238
#define int long long
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

map<int,int>mm[100005];
int tot[100005];


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
    int a[n+1];
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        tot[a[i]%m]++;
        mm[a[i]%m][a[i]]++;
    }
    int ans=0;

        for(int j=1;j<=(m-1)/2;j++)
        {
            int z=m-j;
            ans+=min(tot[j],tot[z]);
            if(tot[j]>tot[z])
            {
                int tt=tot[j]-tot[z];
                for(auto i:mm[j])
                {
                    int k=i.second/2;
                    k*=2;
                    ans+=min(tt,k)/2;
                    tt-=min(tt,k);
                }
            }
            else
            {
                int tt=tot[z]-tot[j];
                for(auto i:mm[z])
                {
                    int k=i.second/2;
                    k*=2;
                    ans+=min(tt,k)/2;
                    tt-=min(tt,k);
                }                
            }            
        }
    ans+=tot[0]/2;
    if(m%2==0)
        ans+=tot[m/2]/2;
    cout<<ans;
} 

