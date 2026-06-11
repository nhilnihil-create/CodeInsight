#include <bits/stdc++.h>

using namespace std;

int getScore[100000];

void hawawa()
{
	int n;
	cin >> n;
	vector<int> p(n);
	for (auto&& i : p) {
		cin >> i;
		i--;
	}
	int ans = 0;
	for (int i = 0; i < n - 1; i++) {
		if (p[i] == i) {
			swap(p[i], p[i + 1]);
			ans++;
		}
	}
	if (p[n - 1] == n - 1) ans++;
	cout << ans << "\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	hawawa();
	return 0;
}
