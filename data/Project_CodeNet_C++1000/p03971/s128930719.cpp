#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
  int n, a, b;
  cin >> n >> a >> b;
  string s;
  cin >> s;
  int cnt1 = 0, cnt2 = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'a' && cnt1 < a + b) {
      cout << "Yes" << endl;
      cnt1++;
    } else if (s[i] == 'b' && cnt1 < a + b && cnt2 < b) {
      cout << "Yes" << endl;
      cnt1++;
      cnt2++;
    } else {
      cout << "No" << endl;
    }
  }
  return 0;
}