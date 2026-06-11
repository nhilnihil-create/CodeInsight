#include <bits/stdc++.h>
using namespace std;
int main(){
	long long n, l, t; cin >> n >> l >> t;
	vector<long long> x(n), w(n);
	for(int i = 0; i < n; i++) cin >> x[i] >> w[i];
	vector<long long> pos[2];
	for(int i = 0; i < n; i++){
		w[i]--;
		pos[w[i]].push_back(x[i]);
	}
	function<int (int, int, int)> count = [&](int p, int x, int y){
		if(x > y) return count(p, x, l) + count(p, 0, y);
		int px = lower_bound(pos[p].begin(), pos[p].end(), x) - pos[p].begin();
		int py = lower_bound(pos[p].begin(), pos[p].end(), y + 1) - pos[p].begin();
		return py - px;
	};
	vector<long long> ans(n);
	t *= 2;
	for(int i = 0; i < n; i++){
		int stp = i;
		if(w[i] == 0){
			stp += pos[1].size() * (t / l) % n;
			int from = x[i], to = (x[i] + (t % l)) % l;
			stp += count(1, from, to);
			stp %= n;
			ans[stp] = (x[i] + (t/2)) % l;
		} else {
			stp += n - (pos[0].size() * (t / l) % n);
			int from = (x[i] - (t % l) + l) % l, to = x[i];
			stp += n - count(0, from, to);
			stp %= n;
			ans[stp] = (x[i] + l - ((t/2)%l)) % l;
		}
	}
	for(int i = 0; i < n; i++) cout << ans[i] << endl;
	return 0;
}
