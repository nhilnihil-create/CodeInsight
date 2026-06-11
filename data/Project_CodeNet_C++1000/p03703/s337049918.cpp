#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 

typedef long long LL;
  
#define ordered_set tree<LL, null_type,less_equal<LL>, rb_tree_tag,tree_order_statistics_node_update> 



const int N = 2e5 + 7;

LL a[N];

int32_t main() {
	ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
	LL n, k, sum = 0, ans = 0; cin >> n >> k;
	ordered_set ost; ost.insert(0);
	for(int i = 1; i <= n; i++) {
		LL x; cin >> x; sum += x;
		LL z = sum - k * i;
		ans += ost.order_of_key(z + 1);
		ost.insert(z);
	}
	cout << ans << endl;
}