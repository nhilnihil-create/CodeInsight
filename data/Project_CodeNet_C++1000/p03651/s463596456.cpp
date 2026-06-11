#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define all(a) a.begin(), a.end()
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<ll,int> pli;
#define rep(i,a,b) for(ll i=a ; i<b ; i++)
#define qrep(que, ite) for(auto ite=begin(que) ; ite!=end(que) ; ite++)
const int max_n = 1e5;
const ll mod = 1e9+7;
const ll INF = 1LL<<60;
const int inf = 1e5;
//typedef long double ld;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
ll mo = 998244353;
ll gcd(ll a, ll b) { return a ? gcd(b%a, a) : b; }
string solve(){
  string ok="POSSIBLE", no="IMPOSSIBLE";
  int n;  ll k;
  cin >> n >> k;
  vector<ll> v(n);
  rep(i,0,n){
    cin >> v[i];
  }
  rep(i,0,n) if(v[i]==k) return ok;
  sort(all(v));
  ll ma = v[n-1];
  if(k>ma)return no;
  ll g = 0;
  rep(i,0,n){
    g = gcd(g, v[i]);
  }
  if(k%g==0) return ok;
  return no;
}
int main(){
  cout << solve() << endl;
  return 0;
}
