#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 100;

int n, a[N];
bool ans, b[N];

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n, greater<int>());
	for (int i = n - 2; ~i; i--)
		b[i] = (a[i] == a[i + 1]? !b[i + 1]: false);
	for (int i = 0; i < n; i++)
		if (i + 1 == a[i]) {
			ans = b[i];
			break;
		}
		else if (a[i] != a[i + 1] && i + 1 >= a[i + 1]) { // i == n - 1 :: ok
			ans = (b[i] ^ ((a[i] - i - 1) & 1));
			if (i + 1 == a[i + 1] && i != n - 1)
				ans |= (!b[i + 1]);
			break;
		}
	cout << (ans? "First": "Second");
}