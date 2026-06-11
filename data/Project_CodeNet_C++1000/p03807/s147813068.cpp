#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] % 2 == 1) cnt++;
  }
  cout << (cnt % 2 == 0 ? "YES" : "NO") << endl;
  return 0;
}