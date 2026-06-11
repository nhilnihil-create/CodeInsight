#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> a(n + 1, 1);
	int t;
	for (int i = 2; i <= n; i++) {
		t = i;
		for (int j = 2; t != 1; j++) {
			while (t % j == 0) {
				t /= j;
				a[j]++;
			}
		}
	}

	long long ans = 1;
	int mod = 1000000007;
	for (int i = 1; i <= n; i++) {
		ans *= a[i];
		ans %= mod;
	}
	cout << ans << endl;

	return 0;
}