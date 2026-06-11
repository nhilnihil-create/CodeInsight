#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O0")
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

  string sa, sb, sc;
  cin >> sa >> sb >> sc;
  sa += "x"; sb += "y"; sc += "z";
  ll a = 0; ll b = 0; ll c = 0;
  string ns = "a";
  while (1) {
    if (ns == "x") {
      cout << "A" << '\n';
      return 0;
    }
    if (ns == "y") {
      cout << "B" << '\n';
      return 0;
    }
    if (ns == "z") {
      cout << "C" << '\n';
      return 0;
    }
    else if (ns == "a") {
      ns = sa[a];
      ++a;
    }
    else if (ns == "b") {
      ns = sb[b];
      ++b;
    }
    else if (ns == "c") {
      ns = sc[c];
      ++c;
    }
  }

  end = chrono::system_clock::now();
  auto elapsed = chrono::duration_cast< chrono::milliseconds >(end - start).count();
  cerr << elapsed << "ms" << '\n';
}