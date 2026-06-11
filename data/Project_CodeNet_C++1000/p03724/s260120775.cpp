#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define _GLIBCXX_DEBUG
const ll MOD = 1000000007;
const ll Mod = 998244353;
const int MAX = 510000;
const double PI = 3.14159265358979;
const vector<int> dx = {1, 0};
const vector<int> dy = {0, 1};

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> a(M), b(M);
  for (int i=0; i<M; i++) cin >> a[i] >> b[i];
  map<int, int> dict;
  for (int i=0; i<M; i++) {
    if (dict.count(a[i])) dict[a[i]]++;
    else dict[a[i]] = 1;
    if (dict.count(b[i])) dict[b[i]]++;
    else dict[b[i]] = 1;
  }
  for (auto p: dict) {
    auto value = p.second;
    if (value%2!=0) {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
  return 0;
}