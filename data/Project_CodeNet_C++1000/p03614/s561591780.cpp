#include<iostream>
using namespace std;
int main() {
	int n, ans = 0, a[114514]; cin >> n; for (int i = 1; i <= n; i++)cin >> a[i];
	for (int i = 1; i <= n; i++) if (a[i] == i) { ans++; i++; }
	cout << ans << endl;
	return 0;
}