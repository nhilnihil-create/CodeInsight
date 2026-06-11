#include<bits/stdc++.h>
using namespace std;
#define MAXN	2005
#define INF	1e9
#define P	1000000007
int cnt, a[MAXN];
void work(long long n) {
	if (n == 1) {
		cnt = 0;
		return;
	}
	if (n % 2 == 0) {
		work(n / 2);
		cnt++; a[cnt] = cnt;
	} else {
		work(n - 1);
		for (int i = cnt; i >= 1; i--)
			a[i + 1] = a[i];
		a[1] = ++cnt;
	}
}
int main() {
	long long n; cin >> n; n++;
	work(n);
	cout << cnt * 2 << endl;
	for (int i = 1; i <= cnt; i++)
		cout << a[i] << ' ';
	for (int i = 1; i < cnt; i++)
		cout << i << ' ';
	cout << cnt << endl;
	return 0;
}