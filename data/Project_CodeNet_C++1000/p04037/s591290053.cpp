#include <bits/stdc++.h>

using namespace std;

const int N = (int) 1e5 + 7;
int n, a[N];

struct T {
  int x;
  int l, r;
};

void check(T it) {
  if (it.l > it.r) {
    cout << "error\n";
    exit(0);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);
  reverse(a + 1, a + n + 1);
  vector<T> col, ran;
  int i = 1;
  while (i <= n) {
    int j = i;
    while (j + 1 <= n && a[j + 1] == a[i]) {
      j++;
    }
    ran.push_back({a[i], i - 1, j});
    i = j + 1;
  }
  for (int i = 1; i <= n; i++) {
    if (a[i] != a[i + 1]) {
      col.push_back({i, a[i + 1], a[i]});
    }
  }
  for (auto &it : col) {
    check(it);
  }
  for (auto &it : ran) {
    check(it);
  }
  bool wi = 0;
  for (auto &it : ran) {
    if (it.l <= it.x && it.x <= it.r) {
      if ((it.r - it.x) % 2 == 1) {
        wi = 1;
      }
    }
  }
  for (auto &it : col) {
    if (it.l <= it.x && it.x <= it.r) {
      if ((it.r - it.x) % 2 == 1) {
        wi = 1;
      }
    }
  }
  if (wi) {
    cout << "First\n";
  } else {
    cout << "Second\n";
  }
}
