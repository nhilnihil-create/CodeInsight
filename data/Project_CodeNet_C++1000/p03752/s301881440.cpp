#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
#include <cmath>
#include <ios>
#include <ctype.h>
#include <stack>
#include <istream>
#include <stdio.h>
#include <map>
#include <set>
#include <queue>
#include <unordered_map>
#include <functional>
#include <bitset>
#include <list>
#include <deque>
#include <time.h>
#include <random>
#include <iomanip>
#include <fstream>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define REP(i,a,b) for (int i = a; i < (b); ++i)
#define RREP(i,a,b) for (int i = a; i > (b); --i)
#define all(x) (x).begin(),(x).end()
#define YY cout << "Yes" << endl
#define NN cout << "No" << endl
const long long INF = 1000000007;
typedef long long ll;
using namespace std;
using Graph = vector<vector<int>>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { return (a * b) / gcd(a,b); }
int solve(){
  ll n,k;
  cin>>n>>k;
  vector<ll>c(n),v(n);
  rep(i,n)cin>>c[i];
  ll ans=31981921122;
  rep(i,(1<<n)){
    ll cost=0,MAX=0;
    if(__builtin_popcount(i)<k)continue;
    rep(j,n){
      if(i & (1<<j)){
        if(MAX>=c[j]){
          cost+=MAX-c[j]+1;
          ++MAX;
        }
      }
      MAX=max(MAX,c[j]);
    }
    ans=min(ans,cost);
  }
  cout<<ans<<endl;
  return 0;
}
int main(){
  // ios::sync_with_stdio(false);cin.tie(nullptr);
  // cout << fixed;cout << setprecision(16);
  solve();
  return 0;
}