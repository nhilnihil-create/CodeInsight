#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;

int n, m, a[N];
int tmp = 0, ans[N];

bool cmp(int x, int y) {
	return (x & 1) > (y & 1);
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= m; ++i)
		cin >> a[i];
	if (m == 1) {
		if (a[1] == 1) {
			return 0 * printf("1\n1\n1\n");
		}
		cout << a[1] << endl;
		puts("2");
		cout << a[1] - 1 << ' ' << 1 << endl;
		return 0;
	}
	sort(a + 1, a + m + 1, cmp);
	int cnt = 0;
	for (int i = 1; i <= m; ++i) {
		if (a[i] & 1) ++cnt;
	}
	if (cnt > 2) return 0 * puts("Impossible");
	if (cnt == 2) swap(a[2], a[m]);
	ans[1] = a[1] + 1, ans[m] = a[m] - 1;
	for (int i = 2; i < m; ++i) {
		ans[i] = a[i];
	}
	for (int i = 1; i <= m; ++i) {
		if (ans[i] > 0) ++tmp;
	}
	for (int i = 1; i <= m; ++i)
		cout << a[i] << ' ';
	puts("");
	cout << tmp << endl;
	for (int i = 1; i <= m; ++i) {
		if (ans[i]) cout << ans[i] << ' ';
	}
	puts("");
}
	
