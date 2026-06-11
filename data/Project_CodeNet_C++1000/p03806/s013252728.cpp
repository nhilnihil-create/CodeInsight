#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define REPR(i,n) for(int i=n; i>-1; --i)
#define ALL(a) (a).begin(),(a).end()
#define INIT(a,n,x); REP(i,(n)){ (a)[i]=(x); }
#define CINA(a,n); REP(i,(n)){ cin >> (a)[i]; }
#define INIT2(a,n,m,x); REP(i,(n)){ REP(j,(m)){(a)[i][j]=(x);} }
#define CINA2(a,n,m); REP(i,(n)){ REP(j,(m)){cin >> (a)[i][j];} }
#define Liny "Yes\n"
#define Linn "No\n"
#define LINY "YES\n"
#define LINN "NO\n"

#define umap unordered_map
//cout << setfill('0') << right << setw(4) << 12; // "0012"
int keta(ll x){ if(x<10){return 1;} else{return keta(x/10) + 1;}}
int keta_wa(ll x){ if(x<10){return x;} else{return keta_wa(x/10) + x%10;} }
int ctoi(char c){ return ( (c>='0' && c<='9')? c - '0': 0 );}
ll gcd(ll a,ll b){if(a<b)swap(a,b); return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){if(a<b){swap(a,b);} return a/gcd(a,b)*b;}

const int nmax=40, abmax=10, inf=10000000;
int N,Ma,Mb;
int a[50],b[50],c[50];
int dp[50][1000][1000];

int solve(){
  cin >> N >>Ma>>Mb;
  REP(i,N){ cin >> a[i] >> b[i] >> c[i];}
  
  REP(i,N+1){
    REP(ca,nmax*abmax+1){
      REP(cb, nmax*abmax+1){
        dp[i][ca][cb] = inf;
      }
    }
  }
  
  dp[0][0][0]=0;
  REP(i,N){
    REP(ca,nmax*abmax+1){
      REP(cb, nmax*abmax+1){
        if(dp[i][ca][cb] == inf){continue;}
        dp[i+1][ca][cb] = min( dp[i+1][ca][cb], dp[i][ca][cb] );
        dp[i+1][ca + a[i]][cb + b[i]] = min( dp[i+1][ca + a[i]][cb + b[i]], dp[i][ca][cb] + c[i] );
      }
    }
  }
  
  int ans = inf;
  for(int ca=1; ca<=nmax*abmax; ++ca){
    for(int cb=1; cb<=nmax*abmax; ++cb){
      if(Ma*cb==Mb*ca){ ans = min(ans,dp[N][ca][cb]); }
    }
  }
  if(ans==inf){ ans = -1;}
  return ans;
}

int main(){
  cout << solve() <<"\n";
}