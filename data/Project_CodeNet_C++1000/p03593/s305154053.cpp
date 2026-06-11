#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define rep(i, n) for (long long i = (long long)(0); i < (long long)(n); ++i)
#define reps(i, n) for (long long i = (long long)(1); i <= (long long)(n); ++i)
#define rrep(i, n) for (long long i = ((long long)(n)-1); i >= 0; i--)
#define rreps(i, n) for (long long i = ((long long)(n)); i > 0; i--)
#define irep(i, m, n) for (long long i = (long long)(m); i < (long long)(n); ++i)
#define ireps(i, m, n) for (long long i = (long long)(m); i <= (long long)(n); ++i)
#define SORT(v, n) sort(v, v + n);
#define REVERSE(v, n) reverse(v, v+n);
#define vsort(v) sort(v.begin(), v.end());
#define all(v) v.begin(), v.end()
#define mp(n, m) make_pair(n, m);
#define cout(d) cout<<d<<endl;
#define coutd(d) cout<<std::setprecision(10)<<d<<endl;
#define cinline(n) getline(cin,n);
#define replace_all(s, b, a) replace(s.begin(),s.end(), b, a);
#define PI (acos(-1))
#define FILL(v, n, x) fill(v, v + n, x);
#define sz(x) long long(x.size())

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vs = vector<string>;
using vpll = vector<pair<ll, ll>>;
using vtp = vector<tuple<ll,ll,ll>>;
using vb = vector<bool>;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const ll INF = 1e9;
const ll MOD = 1e9+7;
const ll LINF = 1e18;



signed main()
{
  cin.tie( 0 ); ios::sync_with_stdio( false );
  ll h,w; cin>>h>>w;
  vs G(h);
  rep(i,h) cin>>G[i];
  
  map<char,ll> m;
  rep(i,h) rep(j,w){
    char c=G[i][j];
    m[c]++;
  }
  
  vll v(4);
  for(auto e: m){
    ll c=e.second/4;
    v[0]+=c;
    ll mod=e.second%4;
    if(mod){
      if(mod==3){
        v[1]++;
        v[2]++;
      }else{
        v[mod]++;
      }
    }
  }
  
  if(h%2==0 && w%2==0){
    if(v[0]*4==h*w) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
  }else if(h%2 && w%2){
    if(v[1]!=1){
      cout<<"No"<<endl;
      return 0;
    }
    
    ll sum=(h-1)/2+(w-1)/2;
    if(v[2]<=sum && (sum-v[2])%2==0){
      cout<<"Yes"<<endl;
    }else{
      cout<<"No"<<endl;
    }
    
  }else{
    if(v[1]!=0){
      cout<<"No"<<endl;
      return 0;
    }
    
    if(w%2) swap(h,w);
    ll sum=w/2;
    if(v[2]<=sum && (sum-v[2])%2==0){
      cout<<"Yes"<<endl;
    }else{
      cout<<"No"<<endl;
    }
    
  }
  
}