#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;

	vector<int> s(n, 1);
	vector<bool> t(n);
	t[0] = true;
	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		
		if (t[a - 1]) {
			t[b - 1] = true;
		}

		s[a - 1]--;
		if (s[a - 1] == 0) {
			t[a - 1] = false;
		}
		s[b - 1]++;
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (t[i]) {
			ans++;
		}
	}
	cout << ans << endl;

	return 0;
}