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
     ll res=1LL;
     while(b>0)
     {
          if(b&1)res=(res*a)%mod;
          a=(a*a)%mod;
          b>>=1;
     }
     return res;
}
 
 
 
 
 
 
 




bool s[405][405];
bool used[405][405];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int main()
{
     ll n;
     cin>>n;
     ll a[n+1];
     for(int i=1;i<=n;i++)cin>>a[i];
     ll res=1LL<<62;
     ll sum=0;
     ll ct=0;
     for(int i=1;i<=n;i++){
          sum+=a[i];
         if(i%2==0){
              if(sum>=0){ct+=abs(sum)+1;
              sum=-1;}
         }
         else if(i%2==1){
              if(sum<=0){ct+=abs(sum)+1;
              sum=1;}
         }
     }
    // cout<<ct<<"\n";
     res=min(res,ct);
     sum=0;ct=0;
     for(int i=1;i<=n;i++){
          sum+=a[i];
          if(i%2==0){
               if(sum<=0){ct+=abs(sum)+1;
               sum=1;}
          }
          else{
               if(sum>=0){ct+=abs(sum)+1;
               sum=-1;}
          }
     }
     res=min(res,ct);
     cout<<res;

}

































