#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
#define mp(a, b) make_pair(a, b)
typedef pair<ll, int> pli; 
template <class T> using Tree = tree<T, null_type, less<T>, 
	rb_tree_tag, tree_order_statistics_node_update>; 
Tree<pli> t;
int n, k;
ll s, ans;
int main()
{
	t.insert(mp(0, 0));
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; ++i)
	{
		int v;
		scanf("%d", &v);
		s += v;
		s -= k;
		ans += t.order_of_key(mp(s, i));
		t.insert(mp(s, i));
	}
	cout << ans << endl;
	return 0;
}