#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int n; cin >> n;
	const int  p = 100001;
	vector<int> num(p, 0);
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		num[a]++;
	}
	int ans = 0;
	for (int i = 0; i < p - 2; i++) {
		int  tmpSum = 0;
		for (int j = 0; j < 3; j++) {
			tmpSum += num[i + j];
		}
		ans = max(ans, tmpSum);
	}
	cout << ans << endl;
	return 0;
}