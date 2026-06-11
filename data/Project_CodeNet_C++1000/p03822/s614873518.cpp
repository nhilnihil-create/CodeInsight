#include <bits/stdc++.h>
#include <boost/range/algorithm.hpp>
#include <boost/range/numeric.hpp>
#include <boost/range/irange.hpp>
#include <boost/range/adaptor/indexed.hpp>

using namespace std;
using namespace boost;
using namespace boost::adaptors;
using ll = int64_t;
using vecint = vector<int>;
using vecll = vector<ll>;

int dfs(const vector<vecint>& tree, int idx) {
  vecint depths;
  for (auto&& child : tree[idx]) {
    depths.push_back(dfs(tree, child));
  }
  sort(depths);
  int cnt = tree[idx].size();
  int mx = cnt;
  for (auto&& p : index(depths)) {
    mx = max(mx, static_cast<int>(cnt-p.index()+p.value()));
  }
  return mx;
}

int main()
{
  int n;
  cin>>n;
  vector<vecint> children(n);
  for(int i : irange(0, n-1)) {
    int a;
    cin>>a;
    --a;
    children[a].push_back(i+1);
  }
  cout<<dfs(children, 0)<<endl;
  return 0;
}
