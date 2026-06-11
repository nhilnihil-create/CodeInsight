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

int main()
{
  int n;
  cin>>n;
  vecint cnt(n, 0);
  int mn = n;
  int mx = 0;
  for(int i:irange(0,n)) {
    int a;
    cin>>a;
    ++cnt[a];
    mn = min(mn, a);
    mx = max(mx, a);
  }
  bool ok = true;
  if (mn < mx / 2) {
    ok = false;
  }
  if (cnt[mx/2] > 1) {
    ok = false;
  }
  if ((mx%2) == 1 && cnt[mx/2+1] != 2) {
    ok = false;
  }
  for(int i:irange(min(mx+1,mx/2+2), mx+1)) {
    if (cnt[i] < 2) {
      ok = false;
    }
  }
  if (!ok) {
    cout<<"Impossible"<<endl;
  } else {
    cout<<"Possible"<<endl;
  }
  return 0;
}
