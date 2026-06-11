#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)



int main() {
  int h, w;
  char s = 'A';
  cin >> h >> w;
  FOR(i, 0, h) {
    FOR(k, 0, w) {
      string in;
      cin >> in;
      if (in == "snuke")
        cout << (char)(s + k) << i + 1 << endl;
    }
  }
}
