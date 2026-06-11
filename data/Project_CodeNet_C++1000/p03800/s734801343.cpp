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
/*int find(int a){
     if(a==par[a])return a;
     return par[a]=find(par[a]);
}
void unite(int a,int b){
     a=find(a),b=find(b);
     if(a==b)return ;
     par[b]=a;
}
ll modexpo(ll a,ll b)
{
     int ans=1LL;
     while(b>0)
     {
          if(b&1)ans=(ans*a)%mod;
          a=(a*a)%mod;
          b>>=1;
     }
     return ans;
}
*/












int r[100005],s[100005];
char st[100005];
int main(){
     int n;
     cin>>n;
     cin>>(st+1);
     for(int i=1;i<=n;i++){
          if(st[i]=='o')s[i]=0;
          else s[i]=1;
     }
     for(int v1=0;v1<2;v1++){
          for(int v2=0;v2<2;v2++){
               r[1]=v1,r[2]=v2;
               for(int i=3;i<=n;i++)r[i]=s[i-1]^r[i-1]^r[i-2];
               if((r[1]==(s[n]^r[n-1]^r[n]))&&(r[n]==(s[1]^r[1]^r[2]))){
                    for(int i=1;i<=n;i++){
                         if(r[i]==1)cout<<"W";
                         else cout<<"S";
                    }
                    return 0;
               }
          }
     }
     cout<<-1;

}

















































