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
  string X;
  cin >> X;
  stack<ll> s;
  for (int i = 0; i < X.size(); i++) {
    if (X[i] == 'S') {
      s.push(X[i]);
    } else if (s.empty() || s.top() == 'T') {
      s.push(X[i]);
    } else if (!s.empty() && s.top() == 'S') {
      s.pop();
    }
  }
  cout << s.size() << endl;
  return 0;
}