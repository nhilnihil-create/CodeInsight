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
  ll h,w,n;
  cin>>h>>w>>n;
  map<ll,set<ll>> table;
  for(ll i:irange(0l,n)) {
    int a,b;
    cin>>a>>b;
    table[a].insert(b);
  }
  vecll cnt(10, 0);
  for(auto itr = begin(table); itr != end(table); ++itr) {
    ll r = itr->first;
    if (r < 3) continue;
    vecint sc;
    auto itr2 = itr;
    while (itr2 != begin(table) && itr2->first >= r-2) --itr2;
    if (itr2->first < r-2) ++itr2;
    auto last = next(itr);
    for (auto itr3 = itr2; itr3 != last; ++itr3) {
      for (auto& c : itr3->second) {
        sc.push_back(max(1l,c-2));
        sc.push_back(max(1l,c-1));
        sc.push_back(c);
        sc.push_back(min(w,c+1));
        sc.push_back(min(w,c+2));
      }
    }
    boost::sort(sc);
    sc.erase(unique(begin(sc),end(sc)), end(sc));
    int mw = sc.size();
    map<int,int> mi;
    for(int i:irange(0,mw)) {
      mi[sc[i]] = i;
    }
    ll lastr = min(r+2, h);
    if (last != end(table)) {
      lastr = min(lastr, last->first-1);
    }
    int mh = lastr - (r-2) + 1;
    vector<vector<bool>> pmat(mh, vector<bool>(mw));
    for (auto itr3 = itr2; itr3 != last; ++itr3) {
      int mr = itr3->first - (r-2);
      for (auto& c: itr3->second) {
        pmat[mr][mi[c]] = true;
      }
    }
    for (int i:irange(0,mh-2)) {
      for (int j:irange(0,mw-2)) {
        int num = 0;
        for (int ki:irange(0,3)) {
          for (int kj:irange(0,3)) {
            if (pmat[i+ki][j+kj]) ++num;
          }
        }
        ++cnt[num];
      }
    }
  }
  ll total = (h-2)*(w-2);
  ll rem = 0;
  for(int i:irange(1,10)) rem += cnt[i];
  cnt[0] = total - rem;
  for(auto ans:cnt) {
    cout<<ans<<endl;
  }
  return 0;
}
