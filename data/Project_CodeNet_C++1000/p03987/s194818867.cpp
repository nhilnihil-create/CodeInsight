#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define pi 3.141592653589793238
#define int long long
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

long long power(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

int lft[200004],rgt[200005];

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
    int a[n+1];
    for(int i=1;i<=n;i++)
        cin>>a[i];
    stack<pair<int,int> >s;
    for(int i=1;i<=n;i++)
    {
        lft[i]=1;
        rgt[i]=n;
    }
    for(int i=1;i<=n;i++)
    {
        while (!s.empty())
        {
            if(s.top().first<a[i])
                break;
            else
            {
                rgt[s.top().second]=i-1;
                s.pop();
            }
        }
        s.push({a[i],i});        
    }

        while (!s.empty())
        {
            s.pop();
        }

    for(int i=n;i>=1;i--)
    {
        while (!s.empty())
        {
            if(s.top().first<a[i])  
                break;
            else
            {
                lft[s.top().second]=i+1;
                s.pop();
            }
        }
        s.push({a[i],i});        
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        int x=rgt[i]-i+1;
        int y=i-lft[i]+1;
        ans+=x*y*a[i];
    }
    cout<<ans;


} 
    
 
