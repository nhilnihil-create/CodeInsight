#include <bits/stdc++.h>
#define l_ength size
using ll = long long;
const int mod = 1000000007;
const int inf = (1<<30);
using namespace std;

int main(){
	int n; cin >> n;
	// v(k) := 要素 k は 1-indexed で何番目にあるか？
	vector<int> v(n+1);
	for( int i = 1; i <= n; ++i ){
		int k; cin >> k;
		v[k] = i;
	}
	set<int> s;
	s.insert(0); s.insert(n+1);
	ll ans = 0;
	// set には必ず自分より小さい要素が入っている
	for( int k = 1; k <= n; ++k ){
		auto itr = s.lower_bound(v[k]);
		int x = *(itr)-v[k];
		int y = v[k]-*(--itr);
		ans += (ll)x * (ll)y * (ll)k;
		s.insert(v[k]);
	}
	cout << ans << endl;
}