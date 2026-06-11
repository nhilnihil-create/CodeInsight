#include "bits/stdc++.h"
using namespace std;
int N;
vector<int>to[100005];

int main() {
	long long x;
	cin >> x;
	long long ans = 0;
	ans += (x / 11) * 2;
	x %= 11;
	if (0 == x) {
	}
	else if (x <=6) {
		ans++;
	}
	else {
		ans += 2;
	}
	cout << ans << endl;
	return 0;
}