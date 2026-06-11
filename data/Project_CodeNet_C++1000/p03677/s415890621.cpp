#include <iostream>
#include <algorithm>
#define int long long
#define rep(i, n) for (i = 0; i < n; i++)
using namespace std;

int n, m;
int a[100000];
int good[200002];

signed main() {
	int i;
	
	cin >> n >> m;
	rep(i, n) { cin >> a[i]; a[i]--; }
	
	int iniCnt = 0;
	rep(i, n - 1) {
		int s = a[i];
		int t = a[i + 1];
		if (t < s) { t += m; }
		//cout << "(s, t) = " << s << " " << t << endl;
		iniCnt += t - s;
	}
	//cout << "iniCnt = " << iniCnt << endl;
	
	rep(i, n - 1) {
		int s = a[i];
		int t = a[i + 1];
		if (t < s) { t += m; }
		good[s + 2]++;
		good[t + 1] -= t - s;
		good[t + 2] += (t - s) - 1;
	}
	
	//cout << "good" << endl;
	//rep(i, 2 * m) cout << good[i] << " "; cout << endl;
	
	rep(i, 2 * m) if (i > 0) good[i] += good[i - 1];
	
	//cout << "good" << endl;
	//rep(i, 2 * m) cout << good[i] << " "; cout << endl;
	
	
	rep(i, 2 * m) if (i > 0) good[i] += good[i - 1];
	
	//cout << "good" << endl;
	//rep(i, 2 * m) cout << good[i] << " "; cout << endl;
	
	
	//for (int j = 0; j < m; j++) {
	//	cout << good[j] << "+" << good[m + j] << endl;
	//}
	
	int ans = 1e+15;
	rep(i, m) {
		ans = min(ans, iniCnt - good[i] - good[m + i]);
	}
	cout << ans << endl;
	return 0;
}