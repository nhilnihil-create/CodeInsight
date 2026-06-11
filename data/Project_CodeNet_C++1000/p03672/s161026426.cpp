#include <iostream>

using namespace std;
using ll = long long;
using ld = long double;

#define ALL(x) begin(x), end(x)
#define REP(i, n) for (size_t i = 0, i##_len = (n); i < i##_len; ++i)

void solve(string S) {
  int i;
  for (i = S.size()/2-1; i;--i) {
    if(S.substr(0,i) == S.substr(i,i)) break;
  }
  cout << i*2 << endl;
}

int main() {
  string S;
  cin >> S;
  solve(S);
  return 0;
}
