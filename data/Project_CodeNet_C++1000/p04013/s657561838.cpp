#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define lint                     long long 
#define setbits(x)              __builtin_popcountll(x)
#define zrbits(x)               __builtin_ctzll(x)
#define zlbits(x)               __builtin_clzll(x)
#define parsbits(x)             __builtin_parityll(x)
#define mem(a, b)               memset(a, (b), sizeof(a))
#define MOD                     1000000007
#define inf                     1e17 
#define neginf                  -1e17 
#define sp(x,y)                 fixed<<setprecision(x)<<y
#define testcase(t)             lint t; cin>>t; while(t--)
#define power(a,b)              (double)pow((double)a,(double)b)
#define FOR(i,n)                for(lint i=0;i<n;i++)
#define gcd(a,b)                __gcd(a,b)
#define PI                      3.1415926535
#define pb                      push_back
#define ss                      second
#define ff                      first
#define umap                    unordered_map           
#define ummap                   unordered_multimap
#define uset                    unordered_set
#define umset                   unordered_multiset

             
typedef unsigned long long   ull;

typedef tree<int,null_type,less<int>,rb_tree_tag,
tree_order_statistics_node_update> indexed_set;
         
void c_p_c()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//    #ifndef ONLINE_JUDGE
  //  freopen("C:\\Users\\pranjal bhatt\\Desktop\\code contests\\input1.txt", "r", stdin);
    //freopen("C:\\Users\\pranjal bhatt\\Desktop\\code contests\\output1.txt", "w", stdout);
    //#endif
}

lint me(lint x, lint y, lint p)  
{  
    lint res = 1;     
     
    x = x % p; 
           
    if (x == 0) return 0; 
          
    while (y > 0)  
    {  
                
        if (y & 1)  
        res = (res*x) % p;  
          
                  
        y = y>>1;  
        x = (x*x) % p;  
    }  
    return res;  
}

    /*---------------------------SOLUTION---------------------------------*/

void solve()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    lint n;
    cin>>n;
    lint a;
    cin>>a;
    lint arr[n];
    lint u=0;
    FOR(i,n){
    cin>>arr[i];
    u+=arr[i];}
    lint dp[u+1][n+1][n+1];
    for(lint i=0;i<=u;i++)
    {
        for(lint j=0;j<n+1;j++)
        {
            for(lint k1=0;k1<=n;k1++)
            {dp[i][j][k1]=0;}
        }
    }
    for(lint i=0;i<=n;i++)
    {
        dp[0][i][0]=1;

    }
    for(lint k1=1;k1<=n;k1++)
    {
        for(lint p=1;p<=k1;p++){
        for(lint x=1;x<=u;x++)
        {
            if(x-arr[k1-1]>=0)
            {
                dp[x][k1][p]=dp[x][k1][p]+dp[x-arr[k1-1]][k1-1][p-1];
            }
            dp[x][k1][p]=dp[x][k1][p]+dp[x][k1-1][p];
            // if(x==8)
            // {
            //     cout<<dp[x][k1][p]<<" "<<k1<<" "<<p<<" ";
            //     cout<<dp[x][k1-1][p]<<endl;
            // }
        }}
    }
    lint sum=0;
    for(lint i=1;i<=u;i++)
    {
        for(lint j=1;j<=n;j++)
        {
            if(i==a*j)
            {
                //cout<<dp[i][n][j]<<" "<<i<<" "<<j<<endl;
                sum+=dp[i][n][j];
            }
        }

    }
    cout<<sum<<endl;
}


int main()
{
    c_p_c();
    lint flg99=0;
    if(flg99==1)
    {
        testcase(t)
        {
             solve();
        }
    }
    else
    {
        solve();
    }
    return 0;
            
}
                
            
                

                

                

