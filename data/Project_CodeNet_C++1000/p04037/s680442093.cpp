#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;

int n, a[N];

int main() {
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	reverse(a + 1, a + n + 1);
	int tmp = 1, r = tmp;
	while (tmp < n && a[tmp + 1] >= tmp + 1)
		++tmp;
	while (a[r + 1] >= tmp) ++r;
	int ans = ((a[tmp] - tmp) & 1) || ((r - tmp) & 1);
	puts(ans ? "First" : "Second");
	return 0;
}
