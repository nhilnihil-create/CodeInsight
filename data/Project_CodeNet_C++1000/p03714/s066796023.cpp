#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i=(a); i<(b); i++)
#define REP(i, n) FOR(i, 0, n)
#define all(x) (x).begin(), (x).end()
#define bit(x) (1L << (x))
using ll = long long;
using namespace std;

template<typename T>
vector<T> make_v(size_t a,T b){return vector<T>(a,b);}
 
template<typename... Ts>
auto make_v(size_t a,Ts... ts){
  return vector<decltype(make_v(ts...))>(a,make_v(ts...));
}

int main() {
  int n; cin >> n;
  auto a = make_v(3 * n, 0LL);

  priority_queue<ll, vector<ll>, greater<ll>> p;
  priority_queue<ll> q;

  ll psum = 0, qsum = 0;
  REP(i, 3 * n){
    cin >> a[i];
    if(i < n){
      p.push(a[i]);
      psum += a[i];
    }
    if(2 * n <= i && i < 3 * n){
      q.push(a[i]);
      qsum += a[i];
    }
  }

  vector<ll> pm(n+1), qm(n+1);
  pm[0] = psum; qm[0] = qsum;

  REP(i, n){
    p.push(a[n + i]); psum += a[n + i];
    psum -= p.top(); p.pop();
    pm[i + 1] = psum;

    q.push(a[2*n - 1 - i]); qsum += a[2* n - 1 - i];
    qsum -= q.top(); q.pop();
    qm[i + 1] = qsum;
  }

  ll ans = numeric_limits<ll>::min();
  FOR(i, 0, n+1){
    ll tmp = pm[i] - qm[n - i];
    ans = max(ans, tmp);
  }
  
  cout << ans << endl;

  return 0;
}
