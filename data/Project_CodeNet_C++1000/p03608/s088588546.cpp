#include<bits/stdc++.h>
using namespace std;
using ull=unsigned long long;
#define mod 1000000007
#define mod2 998244353 
#define PI 3.14159265
#define ll long long
#define ld long double
#define pi pair<ll,ll>
#define pb push_back
#define vi vector<ll>
#define sz size()
#define setbits(x)  __builtin_popcount(x)
#define fi first
#define se second
#define lz length()
#define all(x) (x).begin(),(x).end()
#define scf(x) scanf("%lld",&x)
#define rep(i,n) for(ll i=0;i<n;i++)
const int INF = (int)1e9;
const ll IINF=1LL<<62;
const int maxn=10000005;

//int divr[maxn];
/**/
/*void divisor()
{for(int i=2;i<sqrt(maxn);i++)
     {
          if(!divr[i])
          {
               for(int j=i*i;j<maxn;j+=i)if(!divr[j])divr[j]=i;     
          }
     }
     for(int i=1;i<maxn;i++)if(!divr[i])divr[i]=i;
}*/
 
/*const int N=1000005;
ll n;
struct line {
    long long m, c;
    long long eval(long long x) { return m * x + c; }
    long double intersectX(line l) { return (long double) (c - l.c) / (l.m - m); }
};
vector<pair<pi,ll>> rect;
deque<line> dq;
*/
ll modexpo(ll a,ll b)
{
     ll ans=1LL;
     while(b>0)
     {
          if(b&1)ans=(ans*a)%mod;
          a=(a*a)%mod;
          b>>=1;
     }
     return ans;
}
 
 
 
 
 
 
 
int n,m;
int dp[205][205];
int R;
ll res;
bool used[9];
vector<int> r(9);
void dfs(int c,int last,ll dist){
     if(c==R+1){
          if(res>dist)res=dist;
          return ;
     }
     for(int i=1;i<=R;i++){
          if(!used[i]){
               used[i]=true;
               if(last==-1)dfs(c+1,i,0);
               else dfs(c+1,i,dist+dp[r[last]][r[i]]);
               used[i]=false;
          }
          
     }
}
int main()
{
     cin>>n>>m>>R;
     for(int i=1;i<=R;i++)cin>>r[i];
     for(int i=0;i<=200;i++)for(int j=0;j<=200;j++)dp[i][j]=1e9;
     for(int i=0;i<=200;i++)dp[i][i]=0;
     for(int i=0;i<m;i++){
          int a,b,c;
          cin>>a>>b>>c;
          if(dp[a][b]>c){
               dp[a][b]=c;
               dp[b][a]=c;
          }
               
     } 
     for(int k=1;k<=n;k++){
          for(int i=1;i<=n;i++){
               for(int j=1;j<=n;j++){
                    dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
               }
          }
     }
     res=1LL<<30;
     dfs(1,-1,0);
     cout<<res;
}





















