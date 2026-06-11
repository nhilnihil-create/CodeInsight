#include <bits/stdc++.h>
using namespace std;
int main() {
  int N, x;
  cin >> N >> x;
  int a[N];
  long long y = 0;
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }
  for (int i = 1; i < N; i++) {
    y += min(max(a[i]-x+a[i-1],0),a[i]);
    a[i] -= min(max(a[i]-x+a[i-1],0),a[i]);
  }
  if (a[0] > x) {
    y += a[0]-x;
  }
  cout << y;
}