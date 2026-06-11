#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O0")
typedef long long int ll;
typedef long double ld;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
#define Rep(i,a,n) for (ll i = (a); i < (n); ++i)
const ll mod = 1e9+7;
const ll INF = 1e18;
#define All(a) (a).begin(),(a).end()
#define Pi acos(-1)
using Graph = vector<vector<ll>>;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cout << setprecision(15) << fixed;
  chrono::system_clock::time_point start,end;
  start = chrono::system_clock::now();

  string s;
  cin >> s;
  deque<char> a;
  rep(i,s.size()) {
    if (s[i] == 'B' && !a.empty()) {
      a.pop_back();
    }
    else if (s[i] != 'B'){
      a.push_back(s[i]);
    }
  }
  while (!a.empty()) {
    std::cout << a.front();
    a.pop_front();
  }
  cout << '\n';

  end = chrono::system_clock::now();
  auto elapsed = chrono::duration_cast< chrono::milliseconds >(end - start).count();
  cerr << elapsed << "ms" << '\n';
}