#include <iostream>

using namespace std;

const int MAX_N = 30;

void success () {
  cout << "Yes" << endl;
  exit(0);
}

void failure () {
  cout << "No" << endl;
  exit(0);
}

int cnt [MAX_N];

int main () {
  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      char c;
      cin >> c;

      cnt[c - 'a']++;
    }
  }

  int c4 = 0, c2 = 0, c1 = 0;
  for (int i = 0; i < MAX_N; i++) {
    if (cnt[i] % 4 == 0) c4 += cnt[i] / 4;
    else if (cnt[i] % 2 == 0) c2 += 1;
    else c1 += 1;
  }

  if (n % 2 == 1 && m % 2 == 1) {
    if (c1 == 1 && c2 <= n / 2 + m / 2) {
      success();
    } else {
      failure();
    }
  }

  if (n % 2 == 0 && m % 2 == 0) {
    if (c1 == 0 && c2 == 0) success();
    else failure();
  }

  if (n % 2 == 0) swap(n, m);
  if (c1 == 0 && c2 <= m / 2) success();
  else failure();
}
