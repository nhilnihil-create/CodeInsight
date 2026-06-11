#include<iostream>
#include<algorithm>
using namespace std;

int const MAX = 100005;
long long a[MAX];
long long b[MAX * 2];


int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= m * 2; i++) {
		b[i] = 0;
	}
	for (int i = 1; i <= n - 1; i++) {
		if (a[i] < a[i + 1]) {
			b[a[i] + 1]--;
			b[a[i + 1]]++;
			b[a[i + 1]] += a[i + 1] - a[i] - 1;
			b[a[i + 1] + 1] -= a[i + 1] - a[i] - 1;
		}
		else {
			b[a[i] + 1]--;
			b[a[i + 1] + m]++;
			b[a[i + 1] + m] += a[i + 1] + m - a[i] - 1;
			b[a[i + 1] + m + 1] -= a[i + 1] + m - a[i] - 1;
		}
	}
	for (int i = 2; i <= m * 2; i++) {
		b[i] += b[i - 1];
	}
	for (int i = 1; i <= m; i++) {
		b[i] += b[i + m];
	}
	long long cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] < a[i + 1]) {
			cnt += a[i + 1] - a[i];
		}
		else {
			cnt += a[i + 1];
		}
	}
	long long ans = cnt;
	for (int i = 1; i < m; i++) {
		cnt += b[i];
		ans = min(ans, cnt);
	}
	cout << ans << endl;
}