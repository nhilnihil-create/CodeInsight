#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
  int n, m, k;
  cin >> n >> m >> k;

  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= m; ++j) {
      int t = j * (n - i) + i * (m - j);
      if (t == k) {
	puts("Yes");
	return 0;
      }
    }
  }
  puts("No");
  return 0;
}
