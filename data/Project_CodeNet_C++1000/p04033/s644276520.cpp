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
  ll a, b;
  cin >> a >> b;
  if ((a < 0 && b < 0 && (b - a) % 2 == 1) || (a > 0 && b > 0)) {
    cout << "Positive" << endl;
  } else if ((a < 0 && b < 0 && (b - a) % 2 == 0)) {
    cout << "Negative" << endl;
  } else {
    cout << "Zero" << endl;
  }
  return 0;
}