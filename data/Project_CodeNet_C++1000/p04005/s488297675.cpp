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
  ll a, b, c;
  cin >> a >> b >> c;
  if (a % 2 == 0 || b % 2 == 0 || c % 2 == 0) {
    cout << 0 << endl;
  } else {
    ll cand1 = (a / 2 + 1) * b * c - (a / 2) * b * c;
    ll cand2 = a * (b / 2 + 1) * c - a * (b / 2) * c;
    ll cand3 = (c / 2 + 1) * b * a - (c / 2) * b * a;
    cout << min({cand1, cand2, cand3}) << endl;
  }
  return 0;
}