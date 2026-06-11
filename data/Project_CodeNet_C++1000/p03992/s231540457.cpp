#include <iostream>

using namespace std;
using ll = long long;
using ld = long double;

#define ALL(x) begin(x), end(x)
#define REP(i, n) for (size_t i = 0, i##_len = (n); i < i##_len; ++i)

void solve(string s) {
  s.insert(4," ");
  cout << s << endl;
}

int main() {
  string s;
  cin >> s;
  solve(s);
  return 0;
}
