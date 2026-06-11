#include <iostream>
#include <cctype>
#include <vector>

using namespace std;
using ll = long long;
using ld = long double;

#define ALL(x) begin(x), end(x)
#define REP(i, n) for (size_t i = 0, i##_len = (n); i < i##_len; ++i)

void solve(vector<string> s) {
  for (auto &str : s) {
    cout << (char)toupper((unsigned char)str[0]);
  }
  cout << endl;
}

int main() {
  vector<string> s(3);
  for (int i = 0; i < 3; i++) {
    cin >> s[i];
  }
  solve(move(s));
  return 0;
}
