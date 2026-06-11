#include <bits/stdc++.h>
#include <boost/range/algorithm.hpp>
#include <boost/range/numeric.hpp>
#include <boost/range/irange.hpp>
#include <boost/range/adaptor/indexed.hpp>

using namespace std;
using namespace boost::adaptors;
using namespace std::string_literals;
using ll = int64_t;
using vecint = vector<int>;
using vecll = vector<ll>;
using boost::irange;

int grundy(const vector<vecint>& g, int i, int p) {
  int x = 0;
  for (int c: g[i]) {
    if (c == p) continue;
    x ^= grundy(g, c, i) + 1;
  }
  return x;
}

int main()
{
  int n;
  cin>>n;
  vector<vecint> g(n);
  for(int i:irange(0,n-1)) {
    int x,y;
    cin>>x>>y;
    --x;--y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  int m = grundy(g, 0, -1);
  if (m == 0) {
    cout << "Bob" << endl;
  } else {
    cout << "Alice" << endl;
  }
  return 0;
}
