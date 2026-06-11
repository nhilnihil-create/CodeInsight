#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, a, b, dl, h[N], mx;
bool isval(int cnt) {
	long long ps = 1ll * cnt * b, nd = 0;
	for (int i = 0; i < n; i++) {
		long long x = 1ll * h[i] - ps;
		if (x > 0) 
			nd += 1ll * (x + dl - 1) / dl;
	}
	return nd <= cnt;
}
int findAns() {
	int up = mx, dw = 0;
	while (up - dw > 1) {
		long long md = 1ll * (up + dw) / 2;
		if (isval(md)) 
			up = md;
		else
			dw = md;
	}
	return up;
}
int main() {
	cin >> n >> a >> b;
	dl = a - b;
	for (int i = 0; i < n; i++)
		cin >> h[i], mx = max(mx, h[i]);
	cout << findAns();
	return 0;
}	
