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
    
    int n,m;
    cin>>n>>m;
    int mm[26]={0};
    for(int i=0;i<n;i++)
    {
        string a;
        cin>>a;
        for(int j=0;j<m;j++)
            mm[a[j]-'a']++;
    }
    if(n%2==0&&m%2==0)
    {
        int tot=0;
        for(int i=0;i<26;i++)
            tot+=mm[i]/4;
        if(tot*4==n*m)
        {
            cout<<"Yes";
        }
        else
        {
            cout<<"No";
        }        
    }
    else if(n%2 && m%2)
    {
        int tot=0;
        int x=0,y=0;
        for(int i=0;i<26;i++)
        {
            tot+=mm[i]/4;
            mm[i]%=4;
        }
        for(int i=0;i<26;i++)
        {
            x+=mm[i]/2;
            mm[i]%=2;
        }
        for(int i=0;i<26;i++)
        {
            y+=mm[i];
        }
        int xx=0,yy=0,zz=0;
            xx=(n-1)*(m-1);
            yy=n*m-1-xx;
            zz=1;
        if(tot*4<xx)
        {
            cout<<"No";
            return 0;
        }
        tot-=(xx/4);
        tot*=2;
        if((tot+x)*2<yy)
        {
            cout<<"No";
            return 0;
        }
        tot/=2;
        tot+=xx/4;
        if(tot*4+x*2+y==n*m)
            cout<<"Yes";
        else
            cout<<"No";
    }
    else
    {
        int tot=0;
        int x=0;
        for(int i=0;i<26;i++)
        {
            tot+=mm[i]/4;
            mm[i]%=4;
        }
        for(int i=0;i<26;i++)
        {
            x+=mm[i]/2;
        }
        int xx=0,yy=0;
        if(n%2)
        {
            xx=(n-1)*m;
            yy=n*m-xx;
        }
        else
        {
            xx=n*(m-1);
            yy=n*m-xx;
        }
        
        if(tot*4<xx)
        {
            cout<<"No";
            return 0;
        }
        if(tot*4+x*2==n*m)
            cout<<"Yes";
        else
            cout<<"No";
        
    }
    
    
} 