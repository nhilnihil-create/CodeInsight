//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
using ld = long double;
template<typename T> using V = vector<T>;
template<typename T> using VV = vector<vector<T>>;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound
#define all(v) (v).begin(),(v).end()
#define siz(v) (ll)(v).size()
#define rep(i,a,n) for(ll i=a;i<(ll)(n);++i)
#define repr(i,a,n) for(ll i=n-1;(ll)a<=i;--i)
#define ENDL '\n'
typedef pair<int,int> Pi;
typedef pair<ll,ll> PL;
const ll mod = 1000000007;
const ll INF = 1000000099;
const ll LINF = (ll)(1e18 +99);
const vector<ll> dx={-1,1,0,0},dy={0,0,-1,1};
template<typename T,typename U> inline bool chmin(T& t, const U& u){if(t>u){t=u;return 1;}return 0;}
template<typename T,typename U> inline bool chmax(T& t, const U& u){if(t<u){t=u;return 1;}return 0;}
template<typename T> inline T gcd(T a,T b){return b?gcd(b,a%b):a;}
template<typename T,typename Y> inline T mpow(T a, Y n) {
  T res = 1;
  for(;n;n>>=1) {
    if (n & 1) res = res * a;
    a = a * a;
  }
  return res;
}



signed main(){
  cin.tie(0);ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);
  ll n;cin>>n;
  bool can=true;
  V<int> ans(n*n,0);
  V<bool> ok(n+1,false);
  priority_queue<Pi,V<Pi>,greater<Pi>> q;
  V<int> lat(n+1,0);

  rep(i,1,n+1){
    int x;cin>>x;
    x--;
    rep(j,0,i-1){
      q.push({x,i});
    }

    if(ans[x]){
      can=false;
    }else{
      ans[x]=i;
    }

    lat[i]=n-i;
  }

  rep(i,0,n*n){
    if(ans[i]){
      ok[ans[i]]=true;
      continue;
    }
    else{
      if(q.size()){
        if(q.top().fs<=i)can=false;
        ans[i]=q.top().sc;
        q.pop();
        continue;
      }else{
        rep(j,1,n+1){
          if(ok[j] && lat[j]){
            lat[j]--;
            ans[i]=j;
            goto flag;
          }
        }
      }
    }
    can=false;
    flag:;
  }
  
  if(can){
    cout<<"Yes"<<ENDL;
    rep(i,0,n*n){
      cout<<ans[i]<<' ';
    }
    cout<<ENDL;
  }else{
    cout<<"No"<<ENDL;
  }
}
//( ・ __ ・ ) KEEP BEING ORGANIZED
//CHECK overflow,vector_size,what to output?