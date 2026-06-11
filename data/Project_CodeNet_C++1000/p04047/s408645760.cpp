#include<iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

typedef long long ll;

int a[1005];

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= 2 * n; ++i) {
		cin >> a[i];
	}
	sort(a + 1, a + 2 * n + 1);
	int ans = 0;
	for (int i = 1; i <= 2 * n; i += 2) {
		ans += a[i];
	}
	cout << ans << endl;
	return 0;
}