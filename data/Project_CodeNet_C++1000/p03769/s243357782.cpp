#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <random>
#include <iomanip>
#include <functional>
#include <cassert>
#include <bitset>

using namespace std;

typedef long long ll;

int uk = 1;
deque <int> a, b;

void solve(ll n) {
  if (n == 2) {
    a.push_back(uk);
    b.push_back(uk);
    ++uk;
    return;
  }
  if (n % 2 == 0) {
    solve(n / 2);
    a.push_back(uk);
    b.push_back(uk);
    ++uk;
  } else {
    solve(n - 1);
    a.push_front(uk);
    b.push_back(uk);
    ++uk;
  }
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  ll n;
  cin >> n;
  ++n;
  solve(n);
  cout << a.size() + b.size() << '\n';
  for (int x : a) {
    cout << x << ' ';
  }
  for (int x : b) {
    cout << x << ' ';
  }
}
