#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

const int MOD = 1000000000 + 7;

long long mod_pow(long long x, long long n, long long mod) {
  long long res = 1;
  while (n > 0) {
    // 最下位bitが立っていたら x^{2^i}を掛ける
    if (n & 1) {
      res = res * x % mod;
    }
    x = x * x % mod;
    n >>= 1;
  }
  return res;
}

int main() {
  int n;
  cin >> n;

  map<int, int> mp;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    mp[a]++;
  }

  vector<pair<int, int>> v;
  for (auto it = mp.begin(); it != mp.end(); it++) {
    int val = it->first;
    int cnt = it->second;
    v.push_back(make_pair(val, cnt));
  }

  if (n & 1) {
    bool is_ok = true;
    if (v[0].first != 0 || v[0].second != 1 || v.size() != (n + 1) / 2) {
      is_ok = false;
    }
    for (int i = 1; i < v.size(); i++) {
      if (v[i].second != 2) {
        is_ok = false;
      }
    }
    if (is_ok) {
      cout << mod_pow(2, v.size() - 1, MOD) << endl;
    } else {
      cout << 0 << endl;
    }
  } else {
    bool is_ok = true;
    if (v.size() != n / 2) {
      is_ok = false;
    }
    for (int i = 0; i < v.size(); i++) {
      if (v[i].second != 2) {
        is_ok = false;
      }
    }
    if (is_ok) {
      cout << mod_pow(2, v.size(), MOD) << endl;
    } else {
      cout << 0 << endl;
    }
  }

  return 0;
}