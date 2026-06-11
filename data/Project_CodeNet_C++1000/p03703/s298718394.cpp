/**
 *    author:  tourist
 *    created: 16.11.2019 23:34:45       
**/
#include <bits/stdc++.h>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;

typedef pair<long long, int> tp;
typedef tree<tp,null_type,less<tp>,rb_tree_tag,tree_order_statistics_node_update> pbds;
// tp a;
// T.insert(a), T.erase(a), T.size()
// T.order_of_key(a) -- number of elements strictly less than a
// *T.find_by_order(k) -- k-th element in increasing order

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i] -= k;
  }
  pbds t;
  long long s = 0;
  t.insert(make_pair(s, -1));
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    s += a[i];
    ans += t.order_of_key(make_pair(s + 1, -1));
    t.insert(make_pair(s, i));
  }
  cout << ans << '\n';
  return 0;
}
