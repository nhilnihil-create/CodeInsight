#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using P = pair<ll, ll>;
template <class T>
using V = vector<T>;

string s;

bool dfs(size_t i) {
  if (i == s.length()) return true;

  bool ret = false;
  if (s.find("dream", i) == i) ret |= dfs(i + 5);
  if (s.find("dreamer", i) == i) ret |= dfs(i + 7);
  if (s.find("erase", i) == i) ret |= dfs(i + 5);
  if (s.find("eraser", i) == i) ret |= dfs(i + 6);
  return ret;
}

int main() {
  cin >> s;

  bool ans = dfs(0);
  if (ans) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}
