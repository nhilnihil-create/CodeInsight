#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  int s[n];
  int sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    sum += s[i];
  }
  sort(s, s + n);

  if (!(sum % 10)) {
    for (int i = 0; i < n; i++) {
      if (s[i] % 10) {
        cout << sum - s[i] << endl;
        return 0;
      }
    }
  } else {
    cout << sum << endl;
    return 0;
  }

  cout << 0 << endl;
  return 0;
}