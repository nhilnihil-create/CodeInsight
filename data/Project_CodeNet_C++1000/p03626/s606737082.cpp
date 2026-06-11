#include <iostream>

using namespace std;

const int mod = 1000000007;

int main() {
  int n; cin >> n;  // comment: width
  string s1, s2;
  cin >> s1 >> s2;

  long long ans;
  int i = 0;
  while (i < n) {
    if (i == 0) {
      // 縦棒のとき
      if (s1[i] == s2[i]) {
        ans = 3;
        i += 1;
      } else { // 横棒x2のとき
        ans = 6;
        i += 2;
      }
    } else {
      if (s1[i] == s2[i]) { // 縦棒のとき
        if (s1[i-1] == s2[i-1]) { // ひとつ前も縦棒
          ans *= 2;
        } else {
          ans *= 1;  // ひとつ前は横棒x2
        }
        i += 1;
      } else { // 横棒x2 のとき
        if (s1[i-1] == s2[i-1]) { // ひとつ前は縦棒
          ans *= 2;
        } else {
          ans *= 3;  // ひとつ前も横棒x2
        }
        i += 2;
      }
    }
    ans %= mod;
  }
  cout << ans << endl;
  return 0;
}