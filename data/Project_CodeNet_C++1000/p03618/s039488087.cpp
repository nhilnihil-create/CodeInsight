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

vector<int> manacher(const string &s) {
  int n = s.size();
  vector<int> rad(n);
  int i = 0, j = 0;
  while (i < n) {
    while (i - j >= 0 && i + j < n && s[i - j] == s[i + j]) ++j;
    rad[i] = j;
    int k = 1;
    while (i - k >= 0 && i + k < n && k + rad[i - k] < j) rad[i + k] = rad[i - k], ++k;
    i += k;
    j -= k;
  }
  return rad;
}

int main()
{
  string s;
  cin>>s;
  vecll cnt(26, 0);
  for(auto&& ch:s) {
    ++cnt[ch-'a'];
  }
  ll n=s.size();
  ll ans = n*(n-1)/2+1;
  for(auto&& e:cnt) {
    ans -= e*(e-1)/2;
  }
  cout<<ans<<endl;
  return 0;
}
