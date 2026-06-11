#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;
const int MAX32 = 2147483647;
const double PI = 3.14159265358979323846;

int main() {
  int k, s, cnt = 0;
  cin >> k >> s;
  for (int i = 0; i <= k; i++) {
    for (int j = 0; j <= k; j++) {
      if (s - i - j <= k && i + j <= s) {
        cnt++;
      }
    }
  }
  cout << cnt << endl;
}
