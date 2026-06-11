#include <bits/stdc++.h>
using namespace std;
int main(){
	int n, m; cin >> n >> m;
	vector<int> a(m);
	for(int i = 0; i < m; i++) cin >> a[i];
	vector<int> ans;
	auto add = [&](int x){
		if(x) ans.push_back(x);
	};
	if(m == 1){
		cout << a[0] << endl;
		add(n - 1);
		add(1);
	} else if(m == 2){
		cout << a[0] << " " << a[1] << endl;
		add(a[0] - 1);
		add(a[1] + 1);
	} else {
		int cnt = 0;
		for(int i = 0; i < m; i++) cnt += a[i] % 2;
		if(cnt > 2) return cout << "Impossible" << endl, 0;
		for(int i = 0; i < m; i++) if(a[i] % 2) swap(a[i], a[0]);
		for(int i = 1; i < m; i++) if(a[i] % 2) swap(a[i], a[m - 1]);
		add(a[0] - 1);
		for(int i = 1; i < m - 1; i++) add(a[i]);
		add(a[m - 1] + 1);
		for(int i = 0; i < m; i++) cout << a[i] << " "; cout << endl;
	}
	cout << ans.size() << endl;
	for(int v : ans) cout << v << " "; cout << endl;
	return 0;
}
