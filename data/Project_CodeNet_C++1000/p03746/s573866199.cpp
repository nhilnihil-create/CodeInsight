#include <bits/stdc++.h>

using namespace std;
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)

typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 1LL<<60;

ll gcd(ll a, ll b) {
  if(b == 0) return a;
  return gcd(b, a % b);
}

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

ll modpow(ll a, ll n, ll mod) {
  ll res = 1;
  while (n > 0) {
    if (n & 1) res = res * a % mod;
    a = a * a % mod;
    n >>= 1;
  }
  return res;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;

  vector<vector<int>> g(n);

  rep(i, m){
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  vector<bool> visit(n);
  rep(i, n){
    visit[i] = false;
  }

  queue<int> q;
  q.push(0);
  visit[0] = true;

  vector<int> ans1;
  ans1.push_back(0);
  while(!q.empty()){

    int v = q.front();
    q.pop();
    for(auto nv : g[v]){

      if(visit[nv] == true) continue;

      q.push(nv);
      ans1.push_back(nv);
      visit[nv] = true;
      break;

    }
  }

  vector<int> ans2;
  q.push(0);
  while(!q.empty()){
    int v = q.front();
    q.pop();

    for(auto nv : g[v]){
      if(visit[nv] == true) continue;
      q.push(nv);
      ans2.push_back(nv);
      visit[nv] = true;
      break;
    }
  }

  cout << ans1.size() + ans2.size() << endl;

  rep(i, ans1.size()){
    cout << ans1[ans1.size()-1-i] + 1 << " ";
  }
  rep(i, ans2.size()){
    cout << ans2[i] + 1 << " ";
  }
  cout << endl;

  return 0;
}
