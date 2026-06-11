#include <bits/stdc++.h>
using namespace std;
int main(){
	int n; cin >> n;
	vector<int> t(n), a(n), vt(n, -1), va(n, -1), mx(n, 1<<30);
	for(int i = 0; i < n; i++) cin >> t[i];
	for(int i = 0; i < n; i++) cin >> a[i];
	vt[0] = t[0];
	int lst = 0;
	for(int i = 1; i < n; i++){
		if(t[i] > t[lst]){
			vt[i] = t[i];
			lst = i;
		}
	}
	va[n - 1] = a[n - 1];
	lst = n - 1;
	for(int i = n - 2; i >= 0; i--){
		if(a[i] > a[lst]){
			va[i] = a[i];
			lst = i;
		}
	}
	for(int i = 0; i < n; i++){
		if(va[i] != -1 && vt[i] != -1 && va[i] != vt[i]){
			cout << 0 << endl;
			return 0;
		}
	}
	for(int i = 0; i < n; ){
		int j = i + 1;
		while(j < n && vt[j] == -1){
			mx[j] = min(mx[j], vt[i]);
			j++;
		}
		i = j;
	}
	for(int i = n - 1; i >= 0; ){
		int j = i - 1;
		while(j >= 0 && va[j] == -1){
			mx[j] = min(mx[j], va[i]);
			j--;
		}
		i = j;
	}
	for(int i = 0; i < n; i++){
		if(va[i] != -1 && va[i] > mx[i]){
			cout << 0 << endl;
			return 0;
		}
		if(vt[i] != -1 && vt[i] > mx[i]){
			cout << 0 << endl;
			return 0;
		}
	}
	const int mod = 1'000'000'007;
	auto mul = [&](long long a, long long b){
		return a * b % mod;
	};
	int ans = 1;
	for(int i = 0; i < n; i++) if(va[i] == -1 && vt[i] == -1) ans = mul(ans, mx[i]);
	cout << ans << endl;
	return 0;
}
