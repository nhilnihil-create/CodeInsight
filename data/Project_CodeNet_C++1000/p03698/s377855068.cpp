#include <algorithm>
#include <iostream>

using namespace std;

#define ALL(x) begin(x), end(x)

int main() {
  string S;
  cin >> S;
  sort(ALL(S));
  cout << (unique(ALL(S)) == S.end() ? "yes" : "no") << endl;
  return 0;
}
