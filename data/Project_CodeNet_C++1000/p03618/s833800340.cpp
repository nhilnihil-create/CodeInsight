#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
  string a;
  cin >> a;
  vector<ll> chars(26, 0);
  ll n = a.length();
  for (auto i : a) {
    chars[i - 'a']++;
  }
  ll ans = n * (n - 1) / 2;
  for (auto i : chars) {
    if (i > 1) {
      ans -= i * (i - 1) / 2;
    }
  }
  // 何もしないこともある
  cout << ans + 1 << endl;
}
