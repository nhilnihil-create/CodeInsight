#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
int n, t;
int a[N];
map<int, int> cnt;

int main() {
	scanf("%d %d", &n, &t);
	for (int i = 1; i <= n; ++i) scanf("%d", a + i);
	
	int lst = 0;
	int mx = 0;
	for (int i = n; i >= 1; --i) {
		if (a[i] < lst) mx = max(mx, lst - a[i]), cnt[lst - a[i]]++;
		else lst = a[i];
	}

	cout << cnt[mx] << endl;
}