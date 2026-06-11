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
  ll N;
  cin >> N;
  set<ll> s;
  ll a;
  for (int i = 0; i < N; i++) {
    cin >> a;
    if (s.find(a) == s.end()) {
      s.insert(a);
    } else {
      s.erase(a);
    }
  }
  cout << s.size() << endl;
  return 0;
}