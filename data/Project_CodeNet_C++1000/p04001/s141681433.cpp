#include <iostream>
#include <string>
using namespace std;

int main() {
  string S;
  cin >> S;
  int d = S.size() - 1;
  long long t = 0;

  for (int b = 0; b < (1 << d); ++b) {
    int p = 0;
    for (int i = 0; i <= d; ++i) {
      if (b & (1 << i)) {
        t += stoll(S.substr(p, i + 1 - p));
        p = i + 1;
      }
      if (i == d) {
        t += stoll(S.substr(p));
        p = 0;
      }
    }
  }
  cout << t << endl;
}