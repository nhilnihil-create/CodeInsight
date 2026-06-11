/**
 *    author:  tourist
 *    created: 20.11.2019 07:47:29       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long k;
  cin >> k;
  cout << 50 << '\n';
  vector<long long> a(50, 49);
  for (int i = 0; i < k % 50; i++) {
    a[i] += 50;
    for (int j = 0; j < 50; j++) if (i != j) a[j] -= 1;
  }
  for (int i = 0; i < 50; i++) a[i] += k / 50;
  for (int i = 0; i < 50; i++) cout << a[i] << " ";
  return 0;
}
