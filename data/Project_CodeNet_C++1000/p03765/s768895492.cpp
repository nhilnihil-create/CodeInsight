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
int pre1[100005];
int pre2[100005];

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

    string a,b;
    cin>>a>>b;
    int n=a.length();
    a="#"+a;
    b="#"+b;
    for(int i=1;i<=n;i++)
    {
        if(a[i]=='A')
            pre1[i]=pre1[i-1];
        else
            pre1[i]=pre1[i-1]+1;
    }
    n=b.length();
    n--;
    for(int i=1;i<=n;i++)
    {
        if(b[i]=='A')
            pre2[i]=pre2[i-1];
        else
            pre2[i]=pre2[i-1]+1;
    }

    int q;
    cin>>q;
    int x,y,z,w;
    while (q--)
    {
        cin>>x>>y>>z>>w;
        int tt=pre1[y]-pre1[x-1];
        int ans1=tt*2+(y-x+1)-tt;
        ans1%=3;
        tt=pre2[w]-pre2[z-1];
        int ans2=tt*2+(w-z+1)-tt;
        ans2%=3;
        if(ans1==ans2)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    

} 

