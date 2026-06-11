#include <cmath>

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include <list>

using namespace std;

using ll = long long;
using ld = long double;
using vi = vector<int>;

int n;

vi a;

void input() {
  cin >> n;

  a.resize(n);
  for (auto&& i : a)
    cin >> i;
}

void f(list<int>& a, int what) {
  a.push_front(what);
}

void g(list<int>& a, int what) {
  a.push_back(what);
}

void solve() {
  list<int> ans;

  auto b = vector({f, g});

  if (n % 2 == 0)
    swap(b[0], b[1]);

  for (int i = 0; i < n; ++i)
    b[i % 2](ans, a[i]);

  for (auto&& i : ans)
    cout << i << ' ';

  cout << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cout.precision(16);
  cout << fixed;

  int _times = 1;

#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);

  _times = 4;
#endif

  // cin >> _times;

  while (_times--) {
    input();
    solve();
  }
}
