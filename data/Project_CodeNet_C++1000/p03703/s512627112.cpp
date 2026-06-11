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

    int n,k;
    cin>>n>>k;
    int a[n+1];
    ordered_set<pair<int,int> >s;
    for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            pre[i]=pre[i-1]+a[i]-k;
            s.insert({pre[i],i});
        }
    int ans=0;
    int num=s.order_of_key({0,-1});
    ans+=s.size()-num;
    for(int i=2;i<=n;i++)
    {
        s.erase({pre[i-1],i-1});
        num=s.order_of_key({pre[i-1],-1});
        int sz=s.size();
        ans+=sz-num;
    }
    cout<<ans;



} 

