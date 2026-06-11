#include <bits/stdc++.h>
using namespace std;
int main(){
	int n; cin >> n; n++;
	vector<int> a(n, 0);
	vector<long long> ans(n);
	for(int i = 1; i < n; i++) cin >> a[i];
	int mx = *max_element(a.begin(), a.end());
	int pt = -1;
	for(int i = 0; i < n; i++){
		if(a[i] == mx){
			pt = i;
			break;
		}
	}
	set<pair<int,int> > in_left;
	map<int, long long> occ;
	for(int i = 0; i < pt; i++) in_left.insert({a[i], -i});
	for(int i = pt; i < n; i++) occ[a[i]]++;
	while(pt){
		int up, to;
		tie(up, to) = *(--in_left.end());
		to *= -1;
		long long has = 0, contr = 0;
		while(true){
			auto it = occ.lower_bound(up);
			if(it == occ.end()) break;
			has += it->second;
			contr += (it->first - up) * it->second;
			occ.erase(it);
		}
		ans[pt] += contr;
		occ[up] += has;
		for(int i = to; i < pt; i++) occ[a[i]]++;
		for(int i = to; i < pt; i++) in_left.erase({a[i], -i});
		pt = to;
	}
	for(int i = 1; i < n; i++) cout << ans[i] << endl;
	return 0;
}
