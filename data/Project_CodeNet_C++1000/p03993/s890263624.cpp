#include <bits/stdc++.h>

using namespace std;

typedef long long llint;

int n;
int a[101010];

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i]--;
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int j = a[a[i]];
    if (i == j) ans++;
  }
  cout << ans / 2 << endl;

  return 0;
}