/* In the name of Allah */
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, a[N];

inline void read_input() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
}

inline void solve() {
	sort(a, a + n, greater<int>());
	for (int i = 1; i <= n; i++)
		if (a[i] <= i) {
			int k = 0;
			while (a[i + k] == i)
				k++;
			cout << (k & 1 || a[i - 1] - i & 1? "First": "Second");
			return;
		}
}

int main() {
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	read_input(), solve();
	return 0;
}
