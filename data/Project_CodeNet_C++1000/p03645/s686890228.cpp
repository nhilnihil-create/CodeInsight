#include <algorithm>
#include <iostream>
#include <set>
using namespace std;
int main() {
  int N, M, a, b;
  cin >> N >> M;
  set<int> p, q;
  while (cin >> a >> b) if (a == 1) p.insert(b); else if (b == N) q.insert(a);
  cout << (any_of(begin(p), end(p), [&](int x) { return q.count(x); })
               ? "POSSIBLE" : "IMPOSSIBLE") << endl;
}
