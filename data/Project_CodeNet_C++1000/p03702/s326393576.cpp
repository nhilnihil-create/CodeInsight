#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
long long v[123456];
int n;
long long a, b;
bool can(long long x) {
	long long cnt = 0;
	long long c = a - b;
	for(int i = 0; i < n; i++) {
		long long y = v[i] - x * b;
		if(y > 0) cnt += (y + c - 1) / c;
	}
	return cnt <= x;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> a >> b;
	for(int i = 0; i < n; i++) {
		cin >> v[i];
	}
	long long left = 1, right = 1LL * 1e10;
	while(right - left > 1) {
		long long mid = (left + right) / 2;
		if(can(mid)) right = mid;
		else left = mid;
	}
	cout << (can(left) ? left : right) << endl;
	return 0;	
}