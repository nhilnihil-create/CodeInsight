#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10, MAXN = 4e5 + 10;
int a[N], n, mid, tp[N], b[N];
bool isval(int x) {
	for (int i = 0; i < n; i++)
		if (a[i] >= x)
			b[i] = 1;
		else
			b[i] = 0;
	for (int i = 0; i < n; i++) {
		tp[i] = b[i];
		if (i != 0 && b[i - 1] % 2 == b[i] % 2)
			tp[i] = b[i] + 2;
		else if (i != n - 1 && b[i + 1] % 2 == b[i] % 2)
			tp[i] = b[i] + 2;
	}
	int fr[6] = {MAXN, MAXN, MAXN, MAXN};
	for (int i = 0; i < n; i++) {
		fr[tp[i]] = min(fr[tp[i]], abs(i - mid));
	}
	if (fr[2] == fr[3] && fr[2] == MAXN)
		return (bool) ((b[mid] + mid) % 2);
	else 
		return (fr[3] < fr[2]);
}
int getAns() {
	int up = n, dw = 0;
	while (up - dw > 1) {
		int md = (up + dw) / 2;
		if (isval(md))
			dw = md;
		else
			up = md;
	}
	return dw;
}
int main() {
	cin >> n;
	mid = n - 1, n = 2 * n - 1;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cout << getAns();
	return 0;
}
