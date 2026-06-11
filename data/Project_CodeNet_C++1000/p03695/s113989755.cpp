#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int n; cin >> n;
	const  int p = 8;
	vector<int> num(p + 1, 0);
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		if (a < 3200) num[a / 400]++;
		else num[p]++;
	}
	int	minCnt = 0;
	for (int i = 0; i < p; i++) {
		if (0 < num[i]) minCnt++;
	}
	if (minCnt == 0) {
		cout << 1 << " " << num[p] << endl;
	}
	else cout << minCnt << " " << minCnt + num[p] << endl;
    return 0;
}