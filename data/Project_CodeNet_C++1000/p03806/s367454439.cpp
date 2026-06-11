#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, from, to) for (ll i = from; i < (to); ++i)
#define mp(x,y) make_pair(x,y)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define pb push_back
using ll = long long;
using ld=long double;
using vin=vector<int>;
using vvin=vector<vin>;
using vll=vector<ll>;
using vvll=vector<vll>;
using vst=vector<string>;
using P = pair<ll,ll>;
const int inf=1e9+7;
const ll INF=9e18;
const long double PI = acos(-1.0);
template <typename T> bool chmin(T &a, const T& b){if(a > b){a = b;return true;}return false;}
template <typename T> bool chmax(T &a, const T& b){if(a < b){a = b;return true;}return false;}
template<class T> inline void Yes(T condition){ if(condition) cout << "Yes" << endl; else cout << "No" << endl; }
template<class T> inline void YES(T condition){ if(condition) cout << "YES" << endl; else cout << "NO" << endl; }
const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };
const int F=1000;
bool ex[F][F];

int main(){//cout<<fixed<<setprecision(20);
  ll n,p,q;
  cin>>n>>p>>q;
  vll a(n),b(n),c(n);
  rep(i,0,n)cin>>a[i]>>b[i]>>c[i];
  ll l=(n+1)/2,r;
  r=n-l;
  map<P,ll> lmap,rmap;
  rep(bit,0,(1<<l)){
    ll cnta=0,cntb=0,cntc=0;
   rep(i,0,l){
    if(bit & (1<<i)){
      cnta+=a[i];
      cntb+=b[i];
      cntc+=c[i];
    }
   }
    if(lmap[mp(cnta,cntb)]==0)
    lmap[mp(cnta,cntb)]=cntc;
    else{
      chmin(lmap[mp(cnta,cntb)],cntc);
    }
  }
  rep(bit,0,(1<<r)){
    ll cnta=0,cntb=0,cntc=0;
   rep(i,0,r){
    if(bit & (1<<i)){
      cnta+=a[l+i];
      cntb+=b[l+i];
      cntc+=c[l+i];
    }
   }
    ex[cnta][cntb]=true;
    if(rmap[mp(cnta,cntb)]==0)
    rmap[mp(cnta,cntb)]=cntc;
    else{
      chmin(rmap[mp(cnta,cntb)],cntc);
    }
  }
  
  ll ans=INF;
  for(auto v:lmap){
    ll A=v.first.first;
    ll B=v.first.second;
    rep(i,0,F){
      ll C=i;
      if((q*A+q*C-B*p)%p==0){
      ll D=(q*A+q*C-B*p)/p;
        if(D>=F||D<0)continue;
        if(ex[C][D]){
          if(A+C==0||B+D==0)continue;
         chmin(ans,v.second+rmap[mp(C,D)]); 
        }
      }
    }
  }
  if(ans==INF)ans=-1;
  cout<<ans<<endl;
}


