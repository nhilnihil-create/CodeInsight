#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using vl = vector<ll>;
using vll = vector<vl>;
using Pll = pair<ll, ll>;
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define all(v) v.begin(), v.end()
#define sz(x) ((int) x.size())
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define F first
#define S second
const int MOD = 1e9+7;
const ll INF = 2e15;
template<class T> void print(const T& t){ cout << t << endl; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}

int main(){
  ll n,m;
  cin >> n >> m;
  bool possible = false;
  vl dp1;
  vl dpn;
  rep(i,m){
    ll a, b;
    cin >> a >> b;
    if(a==1){
      dp1.pb(b);
    }
    else if(b==1){
      dp1.pb(a);
    }
    if(a==n){
      dpn.pb(b);
    }
    else if(b==n){
      dpn.pb(a);
    }
  }
  sort(all(dpn));
  rep(i, sz(dp1)){
    if(binary_search(all(dpn),dp1[i])){
      possible = true;
    }
  }
  if(possible){
    print("POSSIBLE");
  }
  else{
    print("IMPOSSIBLE");
  }
}