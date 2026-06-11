#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define REPR(i,n) for(int i=n; i>-1; --i)
#define ALL(a) (a).begin(),(a).end()
#define FILL(a,n,x); REP(i,(n)){ (a)[i]=(x); }
#define CINA(a,n); REP(i,(n)){ cin >> (a)[i]; }
#define FILL2(a,n,m,x); REP(i,(n)){ REP(j,(m)){(a)[i][j]=(x);} }
#define CINA2(a,n,m); REP(i,(n)){ REP(j,(m)){cin >> (a)[i][j];} }
#define Liny "Yes\n"
#define Linn "No\n"
#define LINY "YES\n"
#define LINN "NO\n"

//cout << setfill('0') << right << setw(4) << 12; // "0012"
int keta(ll x){ if(x<10){return 1;} else{return keta(x/10) + 1;}}
int keta_wa(ll x){ if(x<10){return x;} else{return keta_wa(x/10) + x%10;} }
int ctoi(char c){ return ( (c>='0' && c<='9')? c - '0': 0 );}
int __stoi(string s){ return atoi(s.c_str()); }
ll sum(ll a[],ll N){ return accumulate(a,a+N,0LL);}
ll gcd(ll a,ll b){if(a<b)swap(a,b); return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){if(a<b){swap(a,b);} return a/gcd(a,b)*b;}
template<class T> void chmax(T& a, T b){ if(a<b){a=b;} }
template<class T> void chmin(T& a, T b){ if(a>b){a=b;} }
const ll MOD = 1e9+7;
#define pii pair<int,int>
#define pll pair<ll,ll>

int main(){
  ll H,W; cin>>H>>W;
  ll ans = MOD;
  
  if(W%3==0 || H%3==0){ 
    ans = 0;
  }else{ 
    for(int x=0;x<W;++x){
      ll a = x*H;
      ll b = (W-x)*(H/2);
      ll c = (W-x)*((H+1)/2);
      ll t = max( {a,b,c} );
      ll s = min( {a,b,c} );
      chmin(ans, t-s);
      b = (W-x)/2*H;
      c = (W-x+1)/2*H;
      t = max( {a,b,c} );
      s = min( {a,b,c} );
      chmin(ans, t-s);
      if(ans==1){break;}
    }
    for(int y=0;y<H;++y){
      ll a = y*W;
      ll b = (H-y)*(W/2);
      ll c = (H-y)*((W+1)/2);
      ll t = max( {a,b,c} );
      ll s = min( {a,b,c} );
      chmin(ans, t-s);
      b = (H-y)/2*W;
      c = (H-y+1)/2*W;
      t = max( {a,b,c} );
      s = min( {a,b,c} );
      chmin(ans, t-s);
      if(ans==1){break;}
    }
  } 
  cout << ans << "\n";
}
