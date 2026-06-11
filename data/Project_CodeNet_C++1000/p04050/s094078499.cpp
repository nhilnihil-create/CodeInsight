#include <algorithm>
#include <iostream>
using namespace std;

const int MAXN = 105;
int n, m, a[MAXN], f;
bool cmp(int a, int b) {
	return a % 2 < b % 2;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++)
		cin >> a[i], f += a[i] % 2;
	sort(a, a + m, cmp);
	if ((n % 2 == 0 && f == 0) || (n % 2 == 1 && f == 1)) {
		for (int i = 0; i < m; i++)
			cout << a[i] << ' ';
		cout << '\n' << m + 1 - (a[m - 1] == 1) << '\n';
		cout << 1 << ' ';
		for (int i = 0; i < m - (a[m - 1] == 1); i++)
			cout << a[i] - (i == m - 1) << ' ';
		return 0;
	}
	if (n % 2 == 0 && f == 2) {
		for (int i = m - 2; i >= 0; i--)
			swap(a[i], a[i + 1]);
		for (int i = 0; i < m; i++)
			cout << a[i] << ' ';
		cout << '\n' << m - (a[m - 1] == 1) << '\n';
		cout << a[0] + 1 << ' ';
		for (int i = 1; i < m - (a[m - 1] == 1); i++)
			cout << a[i] - (i == m - 1) << ' ';
		return 0;
	}
	cout << "Impossible";
}