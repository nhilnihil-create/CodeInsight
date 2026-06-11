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
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

vector<vector<int> >adj;
int dp[100005];
int a[100005];
bool flag=true;

void dfs(int ver,int pr)
{
    if(!flag)
        return ;
    int mx=-1;
    int tot=0;
    for(auto i:adj[ver])
    {
        if(i!=pr)
        {
            dfs(i,ver);
            tot+=dp[i];
            mx=max(mx,dp[i]);
        }
    }

    if(mx==-1)
        dp[ver]=a[ver];
    else
    {
        int z=tot-a[ver];
        if(z<0)
        {
            flag=false;
            return ;
        }
        if(min(tot-mx,mx)<z && mx>=tot-mx)
        {
            flag=false;
            return ;
        }
        dp[ver]=tot-2*z;        
        if(dp[ver]<0)
        {
            flag=false;
            return ;
        }
    }    
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

    
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    adj.resize(n+1);
    int x,y;
    
    for(int i=0;i<n-1;i++)
    {
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }   
    if(n==2)
    {
        if(a[1]!=a[2])
        {
            cout<<"NO";            
        }
        else
        {
            cout<<"YES";
        }
        return 0;        
    }

    for(int i=1;i<=n;i++)
    {
        if(adj[i].size()>1)
        {
            dfs(i,0);
            if(dp[i]!=0)
            {
                flag=false;
            }
            break;            
        }
    }

    if(!flag)
    {
        cout<<"NO";
    }
    else
    {
        cout<<"YES";
    }
    
} 
    
 
