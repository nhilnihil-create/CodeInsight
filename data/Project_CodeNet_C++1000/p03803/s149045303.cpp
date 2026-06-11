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
  if (a == 1) a = 100;
  if (b == 1) b = 100;
  if (a > b) {
    cout << "Alice" << endl;
  } else if (a < b) {
    cout << "Bob" << endl;
  } else {
    cout << "Draw" << endl;
  }
  return 0;
}