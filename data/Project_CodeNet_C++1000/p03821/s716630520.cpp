#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int n;
  cin >> n;
  vector<long long> a(n);
  vector<long long> b(n);

  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
  }

  long long result = 0;
  for (int i = n - 1; i >= 0; i--) {
    int t = (result + a[i]) % b[i];
    result += (t == 0 ? 0 : b[i] - t);
  }

  cout << result << endl;
  return 0;
}