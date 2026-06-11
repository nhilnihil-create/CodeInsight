#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
const ll mod = 1000000007;
const ll INF = 9223372036854775807;
#define Sort(a) sort(a.begin(), a.end())
#define Bsort(a) sort(a.begin(), a.end(), greater<ll>())
#define Pi acos(-1)

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cout << setprecision(15) << fixed;
  
  string s;
  cin >> s;
  ll ans = 0;
  for (ll i = 0; i < s.size()-1; i++) {
    if (s[i] != s[i+1]) {
      ans++;
    }
  }
  cout << ans << '\n';
}