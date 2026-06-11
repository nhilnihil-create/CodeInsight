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
const int MOD = 1000000007;
const int iINF = 1001001001;
const long long llINF = 1LL << 60;
map<int, int> mp;
int main()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>> a(n, vector<int>(n, 0)), b(n, vector<int>(n, 0));
	string tmp;
	rep(i, n) {
		cin >> tmp;
		rep(j, n) {
			if (tmp[j] == '.')	a[i][j] = 0;
			else a[i][j] = 1;
		}
	}
	rep(i, m) {
		cin >> tmp;
		rep(j, m) {
			if (tmp[j] == '.')	b[i][j] = 0;
			else b[i][j] = 1;
		}
	}
	bool ans = true;
	for (int i = 0; i <= n - m; ++i) {
		for (int j = 0; j <= n - m; ++j) {
			ans = true;
			rep(k, m) {
				rep(l, m) {
					if (a[i + k][j + l] != b[k][l])	ans = false;
					if (!ans)	break;
				}
				if (!ans)	break;
			}
			if (ans) {
				cout << "Yes" << endl;
				return 0;
			}
		}
	}
	cout << "No" << endl;
	return 0;
}
