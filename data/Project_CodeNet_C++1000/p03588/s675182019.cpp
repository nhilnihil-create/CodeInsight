#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
  int n;
  cin >> n;
  vector<pair<int, int>> x(n);
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    x[i] = make_pair(a, b);
  }
  sort(all(x));
  cout << x[n - 1].first + x[n - 1].second << endl;
  return 0;
}