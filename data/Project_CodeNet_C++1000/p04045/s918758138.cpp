#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <map>
#include <queue>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int iINF = 1001001001;
const long long llINF = 1LL << 60;
int main()
{
	// ABC042-C, 1053, 
	int n, k;
	cin >> n >> k;
	vector<int> d(k);
	rep(i, k) cin >> d[i];
	int ans = n;
	while (1) {
		int tmpans = ans;
		bool ok = true;
		while (tmpans != 0) {
			rep(i, k) {
				if (d[i] == tmpans % 10) {
					ok = false; break;
				}
			}
			if (!ok) break;
			tmpans /= 10;
		}
		if (ok) break;
		ans++;
	}
	cout << ans << endl;

	return 0;
}
