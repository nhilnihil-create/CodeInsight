#include <iostream>

using namespace std;

int main()
{
	int n, t;
	cin >> n >> t;

	int a, pa;
	cin >> a;
	pa = a;
	int ans = 0;
	for (int i = 1; i < n; i++) {
		cin >> a;
		ans += (a - pa > t) ? t : a - pa;
		pa = a;
	}
	cout << ans + t << endl;

	return 0;
}