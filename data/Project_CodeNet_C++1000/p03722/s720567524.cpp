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
ll sum(ll a[],ll N){ return accumulate(a,a+N,0LL);}
ll gcd(ll a,ll b){if(a<b)swap(a,b); return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){if(a<b){swap(a,b);} return a/gcd(a,b)*b;}

ll N,M;
ll d[2000];
bool negative[2000];
ll a[3000],b[3000],c[3000];
ll inf = 1000000000000;

int main(){
  cin>>N>>M;
  d[1] = 0;
  for(int i=2;i<=N;++i){ d[i]=inf;  }
  REP(i,M){
    cin >> a[i] >> b[i] >> c[i];
    c[i] = -c[i];
  }
  REP(count,N-1){
    bool fin = true;
    REP(i,M){
      if(d[ a[i] ]==inf){ continue;}
      ll d_cand = d[ a[i] ] + c[i];
      if(d_cand < d[b[i]]){
        d[ b[i] ] = d_cand;
        fin = false;
      }
    }
    if(fin){ break;}
  }
  ll ans = d[N];
  
  for(int i=1;i<=N;++i){ negative[i] = false;}
  REP(count,N){
    REP(i,M){
	  if(d[ a[i] ]==inf){ continue;}
      ll d_cand = d[ a[i] ] + c[i];
      if(d_cand < d[b[i] ]){
        d[b[i]]= d_cand;
        negative[b[i]]=true;
      }
      if(negative[ a[i] ]){
        negative[ b[i] ]=true;
      }
    }
  }
  if(negative[N]){ cout << "inf\n"; }
  else{ cout << -ans <<"\n";}
  
}



