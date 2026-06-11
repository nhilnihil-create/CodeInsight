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

using namespace std;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int a, b, c, d, n;
  cin >> a >> b >> c >> d >> n;
  b = min(b, 2 * a);
  c = min(c, 2 * b);
  d = min(d, 2 * c);
  cout << (ll)(n / 2) * d + (n % 2) * c << '\n';
}

