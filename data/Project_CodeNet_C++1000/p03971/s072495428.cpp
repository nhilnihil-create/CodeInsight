#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <vector>
using namespace std;
typedef long long ll;
ll const INF = 1LL << 60;

int main() {
  ll N, a, b;
  cin >> N >> a >> b;
  ll passed = 0;
  string s;
  cin >> s;
  ll b_cnt = 1;
  for (int i = 0; i < N; i++) {
    if (s[i] == 'a') {
      if (passed < a + b) {
        cout << "Yes" << endl;
        passed++;
      } else {
        cout << "No" << endl;
      }
    }
    if (s[i] == 'b') {
      if (passed < a + b && b_cnt <= b) {
        cout << "Yes" << endl;
        passed++;
      } else {
        cout << "No" << endl;
      }
      b_cnt++;
    }
    if (s[i] == 'c') {
      cout << "No" << endl;
    }
  }
  return 0;
}