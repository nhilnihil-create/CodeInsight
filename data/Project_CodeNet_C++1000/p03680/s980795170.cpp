#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  int a[100010];
  for (int i = 0; i < n; i++) {
    cin >> a[i + 1];
  }
  int c = 0;
  int p = 1;
  for (int i = 0; i < n; i++) {
    c++;
    p = a[p];
    if (p == 2) {
      break;
    }
  }
  if (c == n) {
    cout << "-1" << endl;
  } else {
    cout << c << endl;
  }
  return 0;
}
