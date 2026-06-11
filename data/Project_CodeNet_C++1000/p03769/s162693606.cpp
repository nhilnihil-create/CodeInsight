#include <string.h>
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
// #include <unordered_map>
// #include <unordered_set>
#include <utility>
#include <vector>

#define pb push_back
#define mp make_pair
#define sqr(x) ((x) * (x))

#ifdef ONLINE_JUDGE
#define link renamelink
#define next renamenext
#define prev renameprev
#endif

using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
typedef long double ld;

inline void EnableFileIO(const string& fileName, bool local = 0) {
  if (fileName.empty()) return;
  if (local) {
    freopen((fileName + ".in").c_str(), "r", stdin);
    freopen((fileName + ".out").c_str(), "w", stdout);
    return;
  }
#ifdef ONLINE_JUDGE
  freopen((fileName + ".in").c_str(), "r", stdin);
  freopen((fileName + ".out").c_str(), "w", stdout);
#endif
}

const int INF = (1 << 30) - 1;
const LL LINF = (1LL << 61) - 1;
const double EPS = 1e-10, PI = acos(-1);

LL n;

typedef vector<int> vec;
vec calc(LL k) {
  if (k <= 1) return vec(0);
  vec v;
  if (k & 1) {
    v = calc(k - 1);
    v.insert(v.begin(), (int)v.size());
  } else {
    v = calc(k / 2);
    v.pb((int)v.size());
  }
  return v;
}

int main() {
  // srand((int)time(0));
  // printf("Hello, world!\n");
  // EnableFileIO("");

  cin >> n;
  vec v = calc(n + 1);
  cout << v.size() * 2 << endl;
  for (int i : v) cout << i + 1 << ' ';
  for (int i = 0; i < v.size(); i++) cout << i + 1 << ' ';
  return 0;
}
