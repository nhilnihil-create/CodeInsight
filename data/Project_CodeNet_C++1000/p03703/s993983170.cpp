#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int mod = 1000000007;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
  	ios::sync_with_stdio(false);
    int n, k;
  	ll a[200005] = {}, z = 0;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i], a[i] -= k, a[i] += a[i - 1];
  	ordered_set<pair<ll, int>> s;
  	s.insert({0, 0});
  	for (int i = 1; i <= n; i++) {
    	z += s.order_of_key({a[i] + 1, -1});
      	s.insert({a[i], i});
    }
  	cout << z;
}

