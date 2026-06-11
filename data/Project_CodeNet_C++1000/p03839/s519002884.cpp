#include <bits/stdc++.h>
using namespace std;
int main(){
	int n, k; cin >> n >> k;
	vector<long long> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	long long sum = 0;
	for(int i = 0; i < n; i++) if(a[i] > 0) sum += a[i];
	long long best = 0, all = 0, ins = 0;
	multiset<long long> vals;
	for(int i = 0; i < k; i++) {
		if(a[i] > 0){
			vals.insert(a[i]);
			ins += a[i];
		}
		all += a[i];
	}
	best = max(best, sum - ins);
	best = max(best, sum + all - ins);
	for(int i = k; i < n; i++){
		all += a[i];
		if(a[i] > 0){
			vals.insert(a[i]);
			ins += a[i];
		}
		all -= a[i - k];
		if(a[i - k] > 0){
			vals.erase(vals.find(a[i - k]));
			ins -= a[i - k];
		}
		best = max(best, sum - ins);
		best = max(best, sum + all - ins);
	}
	cout << best << endl;
	return 0;
}

