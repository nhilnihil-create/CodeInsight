#include <vector>
#include <algorithm>
#include <math.h>
#include <iostream>
#include <map>
using namespace std;
const int MAXN = 2 * (int)1e5 + 5;

class DSU {
private:
  std::vector<int> p;
public:
  DSU(int n): p(n, - 1) {}

  int findRep(int x) {
    return p[x] < 0? x: p[x] = findRep(p[x]);
  }

  void unite(int x, int y) {
    int p1 = findRep(x), p2 = findRep(y);
    if (p1 == p2) return;
    if (-p[p1] < -p[p2]) std::swap(p1, p2);
    p[p1] += p[p2];
    p[p2] = p1;    
  }

  int getSize(int x) {
    return -p[findRep(x)];
  }

  bool isSame(int x, int y) {
    return findRep(x) == findRep(y);
  }
};

int main() {
  int n, k, l;
  cin >> n >> k >> l;
  DSU dsu1(n); DSU dsu2(n);
  for (int i = 0; i < k; ++i) {
    int p, q;
    cin >> p >> q;
    p--; q--;
    dsu1.unite(p, q);
  }

  for (int i = 0; i < l; ++i) {
    int r, s;
    cin >> r >> s;
    r--; s--;
    dsu2.unite(r, s);
  }

  map<pair<int, int>, int> m;
  for (int i = 0; i < n; ++i) {
    int x = dsu1.findRep(i), y = dsu2.findRep(i);
    m[pair<int, int>(x, y)]++;
  }

  for (int i = 0; i < n; ++i) {
    int x = dsu1.findRep(i), y = dsu2.findRep(i);
    int ans = m[pair<int, int>(x, y)];
    cout << ans << " ";
  }
  puts("");
  return 0;
}
