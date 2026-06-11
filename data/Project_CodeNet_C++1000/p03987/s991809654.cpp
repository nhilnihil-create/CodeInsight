#include <bits/stdc++.h>
using namespace std;
						
#define fast_cin() ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define endl '\n'
#define int long long
				
int32_t main() {
	fast_cin();  
	int n; cin >> n;
	vector<int> a(n), pos(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		--a[i], pos[a[i]] = i;
	}
	set<int> st = {-1, n};
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		int j = pos[i];
		int l = *(--st.lower_bound(j));
		int r = *st.lower_bound(j);
		ans += (j - l) * (r - j) * (i + 1);
		st.insert(j); 
	}
	cout << ans << endl;
	return 0;
}