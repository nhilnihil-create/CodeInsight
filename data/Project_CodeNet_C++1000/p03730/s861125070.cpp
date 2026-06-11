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
  ll A, B, C;
  cin >> A >> B >> C;
  if (A % B == C) {
    cout << "YES" << endl;
    return 0;
  }
  for (int i = 0; i <= 100; i++) {
    if (A * i % B == C) {
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
  return 0;
}