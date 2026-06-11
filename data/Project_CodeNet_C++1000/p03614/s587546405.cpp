#include<iostream>
#include<string>
#include<algorithm>	
#include<cmath>
#include <vector>
using namespace std;
int main() {
	long long n, a, ans = 0; cin >> n;
	int test[123456] = { 0 };
	for (int h = 1; h <= n; h++) {
		cin >> a; test[h] = a;
	}
	for (int h = 1; h <= n; h++) {
		if (test[h] == h && h != n) {
			int uio = test[h];
			test[h] = test[h + 1];
			test[h + 1] = uio;
			ans++;
		}
		if (test[h] == h && h == n) {
			int uio = test[h];
			test[h] = test[h - 1];
			test[h - 1] = uio;
			ans++;
		}
	}
	cout << ans << endl;
	cin >> n;
}