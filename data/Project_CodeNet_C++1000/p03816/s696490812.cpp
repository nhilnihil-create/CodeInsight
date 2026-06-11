#include <bits/stdc++.h>
using namespace std;

int a[100010];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int ai;
    cin >> ai;
    a[ai]++;
  }
  int ans = 0;
  for (int i = 1; i <= 100000; ++i) {
    if (a[i] > 0) {
      ++ans;
    }
  }
  if (ans % 2 == 0) {
    --ans;
  }
  cout << ans << endl;
}
