#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <climits>
#include <cstdlib>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <vector>
#define DEBUG 1
using namespace std;
constexpr int kMod = 1000000007;
typedef long long LL;

int main() {
  string S; cin >> S;
  int tcnt = 0, scnt = 0;
  for (int i = 0; i < S.size(); ++i) {
    if (S[i] == 'S') {
      ++scnt;
    } else {
      if (scnt > 0) --scnt;
      else          ++tcnt;
    }
  }
  cout << scnt + tcnt << endl;
}
