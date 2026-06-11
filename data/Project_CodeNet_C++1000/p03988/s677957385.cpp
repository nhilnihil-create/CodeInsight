#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100 + 7;
int n, a[N], f[N];

bool ok() {
  if (a[n] % 2 == 0) {
    if (a[1] != a[n] / 2) {
      return 0;
    }
    if (a[2] == a[1]) {
      return 0;
    }
  } else {
    if (a[1] != (a[n] + 1) / 2 || a[2] != (a[n] + 1) / 2) {
      return 0;
    }
    if (a[3] == (a[n] + 1) / 2) {
      return 0;
    }
  }
  for (int i = 1; i <= n; i++) {
    f[a[i]]++;
  }
  for (int x = a[1] + 1; x <= a[n]; x++) {
    if (f[x] < 2) {
      return 0;
    }
  }
  return 1;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);
  if (ok()) {
    cout << "Possible\n";
  } else {
    cout << "Impossible\n";
  }
}
