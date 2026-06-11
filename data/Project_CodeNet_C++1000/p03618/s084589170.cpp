#include <bits/stdc++.h>
using namespace std;

int main() {
  string A;
  cin >> A;
  map<char, long long> m;
  for (char c : A) {
    if (!m.count(c)) m[c] = 1;
    else m[c]++;
  }
  long long ans = 1 + A.size() * (A.size() - 1) / 2;
  for (pair<char, long long> p : m) ans -= m[p.first] * (m[p.first] - 1) / 2;

  cout << ans;
}