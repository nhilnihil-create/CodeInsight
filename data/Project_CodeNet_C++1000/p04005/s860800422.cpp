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


    int a,b,c;
    cin>>a>>b>>c;
    if(a%2==0||b%2==0||c%2==0)
    {
        cout<<0;
    }
    else
    {
        int mn=5e18;
        mn=min(mn,a*b);
        mn=min(mn,b*c);
        mn=min(mn,a*c);
        cout<<mn;
    }
} 
