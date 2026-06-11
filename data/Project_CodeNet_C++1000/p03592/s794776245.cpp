#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <map>
#include <queue>
#include <set>
#include <iomanip>
#include <sstream>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;
const int iINF = 1001001001;
const long long llINF = 1LL << 60;
int main()
{
	int n, m, k;
	cin >> n >> m >> k;
	bool ok = false;
	int cur = 0;
	rep(i, n + 1) {
		cur = i*m;
		rep(j, m + 1) {
			if (j != 0) {
				cur += n;
				cur -= 2 * i;
			}
			if (cur == k) {
				ok = true;
				break;
			}
		}
		if (ok) break;
	}
	if (ok) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}