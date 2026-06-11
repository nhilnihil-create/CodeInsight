#include <bits/stdc++.h>
using namespace std;
int main(){
	int n; cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	long long sum = 0, dv = 0;
	for(int i = 1; i <= n; i++) sum += a[i - 1], dv += i;
	auto bad = [](){
		cout << "NO" << endl;
		exit(0);
	};
	if(sum%dv) bad();
	long long op = sum / dv;
	a.push_back(a[0]);
	for(int i = 0; i < n; i++){
		int fwd = a[i + 1] - a[i];
		if(op - fwd < 0) bad();
		if((op - fwd) % n) bad();
	}
	cout << "YES" << endl;
	return 0;
}
