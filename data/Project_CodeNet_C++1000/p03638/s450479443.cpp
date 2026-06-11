#include <bits/stdc++.h>
using namespace std;

int main() {
  int h, w, n;
  cin >> h >> w >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<int> v;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < a[i]; ++j) {
      v.push_back(i + 1);
    }
  }
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      if (j) {
        cout << " ";
      }
      if (i % 2 == 0) {
        cout << v[i * w + j];
      } else {
        cout << v[i * w + w - 1 - j];
      }
    }
    cout << endl;
  }
}
