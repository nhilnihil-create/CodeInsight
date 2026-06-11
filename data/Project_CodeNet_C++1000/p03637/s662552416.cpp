#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, a;
  cin >> n;
  int two = 0, four = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a;
    if (a%4 == 0) four++;
    else if (a%2 == 0) two++;
  }
  cout << (2*four + two >= n || 2*four+1 == n ? "Yes" : "No") << endl;

  return 0;
}

