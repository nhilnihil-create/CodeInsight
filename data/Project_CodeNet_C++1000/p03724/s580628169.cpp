#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for (int i = 0; i < m; i++) {
		int p, q;
		cin >> p >> q;
		a[p - 1]++;
		a[q - 1]++;
	}

	for (int i = 0; i < n; i++) {
		if (a[i] % 2 == 1) {
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;

	return 0;
}