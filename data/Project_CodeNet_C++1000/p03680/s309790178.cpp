#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int now = 1, cnt = 1;
  while (cnt < n) {
    now = a[now - 1];
    if (now == 2) break;
    cnt++;
  }
  if (now == 2)
    cout << cnt << endl;
  else
    cout << -1 << endl;
  return 0;
}