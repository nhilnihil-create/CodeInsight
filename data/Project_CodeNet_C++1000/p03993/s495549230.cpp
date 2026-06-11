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
    a[i]--;
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (a[a[i]] == i) ans++;
  }
  cout << ans / 2 << endl;
  return 0;
}