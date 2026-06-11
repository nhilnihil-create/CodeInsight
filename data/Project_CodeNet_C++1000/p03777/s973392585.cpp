#include <iostream>

using namespace std;
using ll = long long;
using ld = long double;

#define ALL(x) begin(x), end(x)
#define REP(i, n) for (size_t i = 0, i##_len = (n); i < i##_len; ++i)

void solve(string a, string b) {
  cout << (a==b ? 'H' : 'D') << endl;
}

int main() {
  string a;
  cin >> a;
  string b;
  cin >> b;
  solve(a, b);
  return 0;
}
