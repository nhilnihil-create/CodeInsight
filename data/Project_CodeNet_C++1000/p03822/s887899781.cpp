#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;

const i64 MOD = 1e9+7;

const i64 INF = 1e18+7;


signed main(){

	int n;
	cin >> n;
	vector<int> a(n, -1);
	vector<vector<int>> inv(n);
	for(int i = 1; i < n; ++i){
		cin >> a[i];
		inv[--a[i]].emplace_back(i);
	}

	vector<int> v(n, -1);

	function<void(int)> f = [&](int x){
		vector<int> t;
		for(auto& y : inv[x]){
			if(v[y] == -1)
				f(y);
			t.emplace_back(v[y]);
		}
		if(t.empty()){
			v[x] = 0;
			return ;
		}
		sort(t.begin(), t.end(), greater<int>());
		for(int i = 0; i < t.size(); ++i)
			t[i] += i;
		v[x] = *max_element(t.begin(), t.end()) + 1;
	};
	f(0);
	cout << v[0] << endl;
}
