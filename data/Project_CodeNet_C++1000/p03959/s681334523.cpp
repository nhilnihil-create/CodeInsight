#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n; cin >> n;
	vector<int> t(n+2), a(n+2), h(n+2, 0);
	t[0] = 0;
	a[n+1] = 0;
	for(int i = 1; i <= n; i++){
		cin >> t[i];
		if(t[i] != t[i-1]) h[i] = t[i];
	}
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(int i = n; i >= 1; i--){
		if(a[i] != a[i+1]){
			if(h[i] == 0) h[i] = a[i];
			else{
				if(h[i] != a[i]){
					cout << 0 << endl;
					return 0;
				}
			}
		}
	}
	long long ans = 1;
	for(int i = 1; i <= n; i++){
		if(h[i] == 0){
			ans = (ans * min(t[i], a[i])) % MOD;
		}
		else{
			if(t[i] < h[i] || a[i] < h[i]){
				ans = 0;
				break;
			}
		}
	}
	cout << ans << endl;
	return 0;
}