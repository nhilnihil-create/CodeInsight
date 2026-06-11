#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int N = 101;
int n, m, sum, p, x;
int T[N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> T[i];
    sum += T[i];
  }
  cin >> m;
  for (int i = 0; i < m; ++i) {
    cin >> p >> x;
    int d = T[p] - x;
    cout << sum - d << endl;
  }
  
  return 0;
}
