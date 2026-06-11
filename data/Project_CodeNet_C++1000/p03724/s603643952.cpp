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
int main(){
  int n,m;  cin >> n >> m;
  vector<ll> v(n,0);
  rep(i,0,m){
    ll x,y; cin >> x >> y;  --x; --y;
    v[x]++; v[y]++;
  }
  bool odd = false;
  rep(i,0,n){
    if(v[i]%2==1) odd = true;
  }
  if(odd){
    cout << "NO" << endl;
  }else{
    cout << "YES" << endl;
  }
  return 0;
}
