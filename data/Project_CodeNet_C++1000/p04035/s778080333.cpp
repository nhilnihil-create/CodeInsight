#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a[100005];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  ll n, l;
  cin >> n >> l;

  for (int i = 1; i <= n; i++)
    cin >> a[i];
  for (int i = 1; i <= n; i++) {
    if (a[i] + a[i + 1] >= l) {
      cout << "Possible" << endl;
      for (int j = 1; j < i; j++)
        cout << j << endl;
      for (int j = n - 1; j > i; j--)
        cout << j << endl;
      cout << i << endl;
      return 0;
    }
  }

  cout << "Impossible" << endl;
}
