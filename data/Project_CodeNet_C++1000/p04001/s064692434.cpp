#include <iostream>
using namespace std;

string s;
long long dfs (int a, long long b, long long c) {
  if (a == s.length()) {
    return b + c;
  }
  return dfs(a + 1, b, c * 10 + (s[a] - '0')) + dfs(a + 1, b + c, s[a] - '0');
}

int main(void) {
  cin >> s;
  int len = s.length();
  long long ans = 0LL;
  cout << dfs(1, 0LL, 1LL * (s[0] - '0')) << endl;
  return 0;
}