#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using ll = long long;

int main() {
  ll n;
  cin >> n;
  vector<ll> vec(n);
  for (auto &v : vec)
    cin >> v;

  ll g = vec[0];
  for (int i = 1; i < n; ++i) {
    g = g / __gcd(g, vec[i]) * vec[i];
  }

  cout << g << endl;
}
