#include <iostream>

using namespace std;

int main() {
  int n, m;
  int a[55], b[55];
  int r[55] = {0};
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> a[i] >> b[i];
  }
  for (int i = 0; i < m; i++) {
    r[a[i]]++;
    r[b[i]]++;
  }
  for (int i = 0; i < n; i++) {
    cout << r[i + 1] << endl;
  }
  return 0;
}
