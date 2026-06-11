#include <iostream>
#include <string>
using namespace std;
#define MOD 1000000007

int main() {
  int n; cin >> n;
  string s[2]; cin >> s[0] >> s[1];

  long long ans = 3;
  bool b = true;
  int i = 1;
  if (s[0][0] != s[1][0]) {
    ans = 6;
    b = false;
    i = 2;
  }

  while (i < n) {
    if (s[0][i] == s[1][i]) {
      ans = ans * (b ? 2 : 1) % MOD;
      b = true;
      i++;
    }
    else {
      ans = ans * (b ? 2 : 3) % MOD;
      b = false;
      i += 2;
    }
  }
  cout << ans << endl;
}