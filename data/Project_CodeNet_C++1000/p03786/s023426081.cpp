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
  int n;  cin >> n;
  vector<ll> v(n),sums(n+1,0);
  rep(i,0,n){
    cin >> v[i];
  }
  sort(all(v));
  bool ok[n];
  rep(i,0,n){
    ok[i] = false;
    sums[i+1] = sums[i] + v[i];
  }
  ok[n-1] = true;
  int cnt = 1;
  for(int i=n-2 ; i>=0 ; i--){
    auto ind = upper_bound(all(v), 2*(sums[i+1]))-v.begin();
    if(ok[ind-1]){
      cnt++;
      ok[i] = true;
    }
  }
  cout << cnt << endl;
  return 0;
}
