#include <iostream>

using namespace std;

int main() {
  int n, m;
  int a[55], b[55];
  int c[55], d[55];
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> c[i] >> d[i];
  }
  for (int i = 0; i < n; i++) {
    int p = 1000000000;
    int q = -1;
    for (int j = 0; j < m; j++) {
      int x = abs(a[i] - c[j]) + abs(b[i] - d[j]);
      if (x < p) {
        p = x;
        q = j + 1;
      }
    }
    cout << q << endl;
  }
  return 0;
}
