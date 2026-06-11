#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;

const i64 MOD = 1e9+7;

const i64 INF = 1e18+7;


signed main(){
	i64 i, o, t, j, l, s, z;
	cin >> i >> o >> t >> j >> l >> s >> z;
	i64 p = min({i, j, l});
	i -= p;
	j -= p;
	l -= p;
	i64 ans =  3 * p + (i & ~1) + o +  (j & ~1) + (l & ~1);
	if(p){
		--p, ++i, ++j, ++l;
		ans = max(ans, 3 * p + (i & ~1) + o +  (j & ~1) + (l & ~1));
	}
	cout << ans << endl;
}
