#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

int main(){
	long long n, ans = (long long)1e18;
	cin >> n;
	vector<long long> a(n + 1);
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		a[i] += a[i - 1];
	}
	for(int i = 1; i < n; i++){
		long long x, y;
		x = a[i];
		y = a[n] - a[i];
		ans = min(ans, abs(x - y));
	}
	cout << ans << endl;
	return 0;
}