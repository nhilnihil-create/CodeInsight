#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(int argc, const char *argv[]) {
  ll n;
  cin >> n;

  vector<pair<ll, ll>> vab(n);
  for (auto &p : vab) {
    cin >> p.first >> p.second;
  }

  sort(vab.begin(), vab.end());

  auto last = vab.back();
  cout << last.first + last.second << '\n';
}