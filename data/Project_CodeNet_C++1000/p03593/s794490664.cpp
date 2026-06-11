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
 
 
 
 
 
 
 







int dp[200][200];
int x[100][100],y[100][100];
int main()
{
    int h,w;
    cin>>h>>w;
    vector<string> str(h);
    for(int i=0;i<h;i++){
         cin>>str[i];
    }
    int a[26]={0};
    for(int i=0;i<h;i++){
         for(int j=0;j<str[i].length();j++){
              a[str[i][j]-'a']++;
         }
    }
    int g4=0,g2=0,g1=0;
    for(int i=0;i<h;i++){
         for(int j=0;j<w;j++){
              if(h-1-i<i)continue;
              if(w-1-j<j)continue;
              int c=0;
              if(h-1-i==i)c++;
              if(w-1-j==j)c++;
              if(c==0)g4++;
              else if(c==1)g2++;
              else g1++;
         }
    }
    int t=0;
    for(int i=0;i<26;i++){
        t=a[i]/4;
        t=min(t,g4);
        g4-=t;
        a[i]-=t*4;
        t=a[i]/2;
        t=min(t,g2);
        g2-=t;
        a[i]-=t*2;
        t=a[i]/1;
        t=min(t,g1);
        g1-=t;
        a[i]-=t*1;
        if(a[i]!=0){cout<<"No";return 0;}
     }
     cout<<"Yes";
     
}
























