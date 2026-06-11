#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, x;
  cin >> n >> x;
  if (x == 1 || x == 2 * n - 1) {
    cout << "No" << endl;
    return 0;
  }
  cout << "Yes" << endl;
  if (x == n) {
    for (int i = 1; i <= 2 * n - 1; i++) {
      cout << i << endl;
    }
    return 0;
  }

  vector<int> bs(2 * n - 1, -1);
  vector<int> used(2 * n);
  if (x < n) {
    bs[n - 1] = 1;
    bs[n] = x;
    bs[n - 2] = x + 1;
    bs[n + 1] = x + 2;
    used[1] = used[x] = used[x + 1] = used[x + 2] = true;
    int current = 1;
    for (int i = 0; i < 2 * n - 1; i++) {
      if (bs[i] < 0) {
        while (used[current]) current++;
        bs[i] = current;
        used[current] = true;
      }
    }

    for (int i = 0; i < 2 * n - 1; i++) {
      cout << bs[i] << endl;
    }
  } else {
    bs[n - 1] = 2 * n - 1;
    bs[n] = x;
    bs[n - 2] = x - 1;
    bs[n + 1] = x - 2;
    used[2 * n - 1] = used[x] = used[x - 1] = used[x - 2] = true;
    int current = 1;
    for (int i = 0; i < 2 * n - 1; i++) {
      if (bs[i] < 0) {
        while (used[current]) current++;
        bs[i] = current;
        used[current] = true;
      }
    }

    for (int i = 0; i < 2 * n - 1; i++) {
      cout << bs[i] << endl;
    }
  }
}
