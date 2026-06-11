#include<iostream>
#include<algorithm>
using namespace std;

int n, m, num, max1, max2, ans, a[100005];

int main() {
	max1 = max2 = ans = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)cin >> a[i];
	for (int i = n; i; i--) {
		max1 = max(a[i], max1);
		num = max(max1 - a[i], num);
	}
	for (int i = n; i; i--) {
		max2 = max(a[i], max2);
		if (max2 - a[i] == num)ans++;
	}
	cout << ans << endl;
	return 0;
}