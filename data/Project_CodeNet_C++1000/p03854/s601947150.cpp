#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
const ll mod = 1000000007;
const ll INF = 9223372036854775807;
#define Sort(a) sort(a.begin(), a.end())
#define Reverse(a) reverse(a.begin(), a.end())
#define Pi acos(-1)

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cout << setprecision(15) << fixed;
  string s;
  cin >> s;
  rep(i,25000) {
    if (s == "") {
      cout << "YES" << '\n';
      return 0;
    }
    else if (s[0] == 'e') {
      if (s.substr(0,5) == "erase") {
        if (s[5] ==  'r') s.erase(0,6);
        else s.erase(0,5);
      }
    }
    else if (s[0] == 'd') {
      if (s.substr(0,5) == "dream") {
        if (s.substr(5,5) == "erase") s.erase(0,5);
        else if (s.substr(5,2) == "er") s.erase(0,7);
        else s.erase(0,5);
      }
    }
  }
  cout << "NO" << '\n';
}