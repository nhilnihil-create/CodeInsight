#include <iostream>
#include <string>

using namespace std;
using ll = long long;

#define ALL(x) begin(x), end(x)
#define REP(i, n) for (size_t i = 0, i##_len = (n); i < i##_len; ++i)

string CF = "CODEFESTIVAL2016";

void solve(string S) {
  int cnt{};
  for(auto i = 0; i != 16; ++i) {
    if(S[i] != CF[i]) ++cnt;
  }
  cout << cnt << endl;
}

int main() {
  string S;
  cin >> S;
  solve(S);
  return 0;
}
