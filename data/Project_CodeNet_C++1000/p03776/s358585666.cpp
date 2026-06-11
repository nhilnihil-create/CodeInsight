#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
typedef long long ll;
#define MOD 1000000007
using namespace std;

int main() {
  vector<vector<ll>> C(100, vector<ll>(100, 0));
  C[0][0] = 1;
  C[1][0] = 1;
  for (int i = 1; i < 100; i++) {
    C[i][0] = 1;
    for (int j = 1; j <= i; j++) {
      C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
    }
  }
  ll n, a, b;
  cin >> n >> a >> b;
  vector<ll> v(n);
  map<ll, ll> mp;
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    mp[v[i]]++;
  }
  sort(all(v), greater<ll>());
  double mean = 0;
  for (int i = 0; i < a; i++) {
    mean += v[i];
  }
  cout << fixed << setprecision(12) << mean / a << endl;
  if (v[0] == v[a - 1]) {
    for (int i = a; i <= b; i++) {
      ans += C[mp[v[0]]][i];
    }
  } else {
    int k = 0;
    for (int i = 0; i < a; i++) {
      k += v[i] == v[a - 1];
    }
    ans += C[mp[v[a - 1]]][k];
  }
  cout << ans << endl;
}
