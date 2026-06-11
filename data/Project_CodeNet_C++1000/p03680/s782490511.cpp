#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  cin >> N;
  int a[N];
  for (int i = 0; i < N; cin >> a[i], a[i++]--);
  vector<bool> b(N);
  for (int i = 0, j = 0; !b[i]; i = a[i], j++) {
    b[i] = true;
    if (i == 1) {
      cout << j;
      return 0;
    }
  }
  cout << -1;
}