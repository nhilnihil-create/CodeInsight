#include <math.h>

#include <algorithm>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, a, b;
  cin >> n >> a >> b;
  string s;
  cin >> s;

  int dom = 0;
  int foe = 0;

  rep(i, s.size()) {
    if (s[i] == 'a') {
      if (dom + foe < a + b) {
        cout << "Yes" << endl;
        dom++;
      } else {
        cout << "No" << endl;
      }
    } else if (s[i] == 'b') {
      if (dom + foe < a + b && foe + 1 <= b) {
        cout << "Yes" << endl;
        foe++;
      } else {
        cout << "No" << endl;
      }
    } else {
      cout << "No" << endl;
    }
  }

  return 0;
}
