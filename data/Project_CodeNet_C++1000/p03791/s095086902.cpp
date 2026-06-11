#include <bits/stdc++.h>
using namespace std;
const int mod = 1'000'000'007;
int mul(long long a, long long b){
	return a * b % mod;
}
int main(){
	int n; cin >> n;
	vector<int> a(n), b;
	for(int i = 0; i < n; i++) cin >> a[i];
	int ans = 1, len = 0;
	for(int i = 0; i < n; i++){
		b.push_back(a[i]);
		len++;
		while(!b.empty() && b.back() < 2 * len - 1){
			b.pop_back();
			ans = mul(ans, len);
			len--;
		}
	}
	while(!b.empty()){
		b.pop_back();
		ans = mul(ans, len);
		len--;
	}
	cout << ans << endl;
	return 0;
}
