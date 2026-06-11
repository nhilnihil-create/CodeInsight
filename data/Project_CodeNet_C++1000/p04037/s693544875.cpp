#include <bits/stdc++.h>


using namespace std;



const int MAXN = 100 * 1000 + 23;













int n, a[MAXN];




int main() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n, greater<int>());
	int tmp, cnt = 0;
	for (int i = 0; i < n; i++)
		if (a[i + 1] < i + 2) {
			tmp = i;
			break;
		}
	for (int i = tmp; i < n; i++) if (a[i] >= tmp + 1) cnt++;
	if ((cnt - 1) & 1 || (a[tmp] - tmp + 1) & 1) cout << "First";
	else cout << "Second";
	return 0;
}