#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
typedef long long int ll;
typedef long double ld;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
const ll mod = 1e9+7;
const ll INF = 1e18;
#define All(a) (a).begin(),(a).end()
#define Pi acos(-1)

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cout << setprecision(15) << fixed;
  chrono::system_clock::time_point start,end;
  start = chrono::system_clock::now();

  ll n;
  cin >> n;
  deque<ll> a;
  rep(i,n) {
    ll t;
    cin >> t;
    if (i%2 == 0) {
      a.push_front(t);
    }
    else {
      a.push_back(t);
    }
  }
  if (n%2 == 0) {
    for (auto itr = a.end()-1; itr != a.begin()-1; --itr) {
      cout << *itr << ' ';
    }
  }
  else {
    for(auto itr = a.begin(); itr != a.end(); ++itr) {
       cout << *itr << ' ';
    }
  }

  end = chrono::system_clock::now();
  auto elapsed = chrono::duration_cast< chrono::milliseconds >(end - start).count();
  cerr << elapsed << "ms" << '\n';
}