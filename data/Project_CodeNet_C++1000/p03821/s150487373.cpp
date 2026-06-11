//確定するものから決める. iが大きい方から決める.
#include <iostream>
#define int long long
using namespace std;

int n;
int a[100000], b[100000];

signed main() {
	int i;
	
	cin >> n;
	for (i = 0; i < n; i++) cin >> a[i] >> b[i];
	
	int cnt = 0;
	for (i = n - 1; i >= 0; i--) {
		int r = (a[i] + cnt) % b[i];
		if (r == 0) r = b[i];
		cnt += b[i] - r;
	}
	cout << cnt << endl;
	return 0;
}