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

char G[105][105];

void fail(){
  cout << "No" << endl;
  exit(0);
}

signed main()
{
  cin.tie( 0 ); ios::sync_with_stdio( false );
  ll h,w; cin>>h>>w;
  
  rep(i,h) rep(j,w) cin>>G[i][j];
  map<char,ll> m;
  rep(i,h) rep(j,w) m[G[i][j]]++;
  
  map<ll,ll> mod4;
  for(auto e: m){
    mod4[e.second%4]++;
  }
  mod4[1]+=mod4[3];
  mod4[2]+=mod4[3];
  
  if(h%2==0 && w%2==0){
    if(mod4[1] || mod4[2]){
      
      fail();
    }
  }else if(h%2 && w%2){
    if(mod4[1]!=1 || mod4[2]>(h-1)/2+(w-1)/2){
      fail();
    }
  }else{
    if(w%2) swap(h,w);
    if(mod4[1] || mod4[2]>w/2){
      fail();
    }
  }
  
  cout<<"Yes"<<endl;
}
