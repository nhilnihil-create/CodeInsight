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
  ll x;
  cin>>n>>x;
  vecll a(n);
  for(auto&& e:a) cin>>e;
  ll sum = 0;
  for(auto&& e:a) sum += e;
  ll ans = sum;
  vecll mn = a;
  for(auto&& i:irange(0,n)) {
    vecll nx = a;
    for(auto&& j:irange(0,n)) {
      int old = (j + n - 1) % n;
      nx[j] = min(a[j], mn[old]);
    }
    ll sum = 0;
    for(auto&& e:nx) sum += e;
    ans = min(ans, sum + (i+1) * x);
    swap(mn, nx);
  }
  cout<<ans<<endl;
  return 0;
}
