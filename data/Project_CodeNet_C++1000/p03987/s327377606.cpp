#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <numeric>
#include <functional>
#include <cmath>
#include <cassert>
#include <string>
#include <iostream>

using namespace std;
typedef long long ll;


ll a[202020];
int solve()
{
   ll n;
   cin >> n;
   map<ll, ll> m;
   for (int i = 0; i < n; i++){
      cin >> a[i];
      m[a[i]] = i + 1;
   }

   set<ll> se;
   se.insert(0);
   se.insert(n + 1);
   ll ans = 0;
   for(ll i=1; i <= n; i++){
      ll l, r;
      auto it = se.lower_bound(m[i]);
      r = *it;
      it--;
      l = *it;
      ans += (m[i] - l) * (r - m[i])*i;
      se.insert(m[i]);
   }

   cout << ans << endl;

   return 0;
}
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);

   solve();
}