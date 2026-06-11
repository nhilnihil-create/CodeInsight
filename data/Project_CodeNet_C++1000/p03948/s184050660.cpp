#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);  
	int n, t;
	cin >> n >> t;
	vector<int> v(n);
	int dif = 0, mi;
	for(int i = 0; i < n; i++) {
		cin >> v[i];
		if(i == 0) mi = v[i];
		else {
			dif = max(dif, v[i] - mi);
			mi = min(v[i], mi);
		}
	}
	set<int> st;
	int ans = 0;
	for(int i = 0; i < n; i++) {
		if(st.count(v[i] - dif)) ans++;
		st.insert(v[i]);
	}
	cout << ans << endl;
	return 0;	
}