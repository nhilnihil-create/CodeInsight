#include <bits/stdc++.h>
#define exrep(i, a, b) for(long long i = a; i <= b; i++)
#define rep(i,n)for(long long i=0;i<(long long)(n);i++)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> P;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<vector<P>> vvp;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
 
const ll MOD=1e9+7;
const ll INF=1e18;
const int MAX=510000;
const double pi=acos(-1);
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

ll gcd(ll x ,ll y){
  if(x%y==0)return y;
  return gcd(y,x%y);
}
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false); 
  
  ll n ,k;
  cin >> n >> k;
  vl vec(n);
  ll g;
  rep(i,n){
    cin >> vec[i];
    if(vec[i]==k){
      cout << "POSSIBLE" << endl;
      return 0;
    }
  }
  if(k>*max_element(all(vec))){
    cout << "IMPOSSIBLE" << endl;
    return 0;
  }
  g=vec[0];
  rep(i,n){
    g=gcd(g,vec[i]);
  }
  if(k%g==0) cout << "POSSIBLE" << endl;
  else cout << "IMPOSSIBLE" << endl;
  return 0;     
}
