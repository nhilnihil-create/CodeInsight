#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = (int) 1e5 + 7;
int n;
ll need, s[N], a[N];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> need;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i < n; i++) {
    if (a[i] + a[i + 1] >= need) {
      cout << "Possible\n";
      for (int j = 1; j < i; j++) {
        cout << j << "\n";
      }
      for (int j = n; j > i; j--) {
        cout << j - 1 << "\n";
      }
      return 0;
    }
  }
  cout << "Impossible\n";
}

