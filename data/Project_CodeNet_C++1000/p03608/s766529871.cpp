#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define REPR(i,n) for(int i=n; i>-1; --i)
#define ALL(a) (a).begin(),(a).end()
#define FILL(a,x); REP(i,sizeof(a)){ (a)[i]=(x); }
#define CINA(a,n); REP(i,(n)){ cin >> (a)[i]; }
#define FILL2(a,n,m,x); REP(i,(n)){ REP(j,(m)){(a)[i][j]=(x);} }
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

ll inf = 1000000007;

int N,M,R,a,b,c;
int r[8];
ll d[201][201];
void do_wf(){
  for (int k = 1; k <= N; k++){
    for (int i = 1; i <= N; i++) { 
      for (int j = 1; j <= N; j++) {
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }
}

int main(){
  cin >>N>>M>>R;
  REP(i,R){ cin >>r[i];} sort(r,r+R);
  FILL2(d,N+1,N+1,inf);
  REP(i,M){
    cin >> a>> b>> c;
    d[a][b] = c;
    d[b][a] = c;
  }
  do_wf();
  
  ll ans = inf-1;
  do {
    ll t = 0;
    REP(i,R-1){
      t += d[ r[i] ][ r[i+1] ];
      if(t>=ans){break;}
    }
    if(t<ans){ ans = t;}
  } while (next_permutation(r,r+R));
  cout << ans <<"\n";
}