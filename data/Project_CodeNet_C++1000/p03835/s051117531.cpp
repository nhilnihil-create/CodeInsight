#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <limits>
#include <numeric>
#include <string>
#include <vector>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
using namespace std;
int main() {
  int k, s, cunt = 0;
  cin >> k >> s;
  rep(x, k + 1) {
    rep(y, k + 1) {
      int z = s - x - y;
      if (z >= 0 && z <= k) {
        cunt++;
      }
    }
  }
  cout << cunt << endl;
}