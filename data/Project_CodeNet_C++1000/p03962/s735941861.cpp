#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;
const int INF = 1e9;

int main() {
  int a, b, c, cnt = 1;
  cin >> a >> b >> c;
  if (a != b) cnt++;
  if (a != c && b != c) cnt++;
  cout << cnt << endl;
}
