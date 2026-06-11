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
/*ll modexpo(ll a,ll b)
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
int find(int a){
     if(par[a]==a)return a;
     return par[a]=find(par[a]);
}
void unite(int a,int b){
     a=find(a),b=find(b);if(a==b)return ;
     parent[b]=a;
}*/
 
 
 
 
 
 
 

int dp[105][105];
int main()
{
     int n,m;
     cin>>n>>m;
     for(int i=0;i<=n;i++){
          for(int j=0;j<=n;j++)if(i==j)dp[i][j]=0;
          else dp[i][j]=1e9;
     }
     int a[1005],b[1005],c[1005];
     for(int i=0;i<m;i++){
          cin>>a[i]>>b[i]>>c[i];
          dp[a[i]][b[i]]=c[i];
          dp[b[i]][a[i]]=c[i];
     }
     for(int k=1;k<=n;k++){
          for(int i=1;i<=n;i++){
               for(int j=1;j<=n;j++){
                    dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
               }
          }
     }
     int ans=m;
     for(int i=0;i<m;i++){
          bool shpath=false;
          for(int j=1;j<=n;j++){
               if(dp[j][a[i]]+c[i]==dp[j][b[i]])shpath=true;
          }
          if(shpath)ans-=1;
     }
     cout<<ans; 
}






















