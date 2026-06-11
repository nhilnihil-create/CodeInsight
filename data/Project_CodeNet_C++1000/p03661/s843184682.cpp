#include<iostream>
#include<vector>
#include<string>
#include<algorithm>	
#include<cmath>
using namespace std;
int main() {
	long long n, a, sum = 0, num = 0, ans = 999999999999; cin >> n;
	int test[223456] = { 0 };
	for (int h = 0; h < n; h++) {
		cin >> a; test[h] = a;
		num += test[h];
	}
	sum += test[0]; num -= test[0];
	ans = min(ans, abs(sum - num));
	for (int h = 1; h < n - 1; h++) {
		sum += test[h];
		num -= test[h];
		ans = min(ans, abs(sum - num));
	}
	cout << ans << endl;
	cin >> n;
}
