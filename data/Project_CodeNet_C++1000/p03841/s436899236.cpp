#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cmath>
#define int long long
#define mod 1000000007
#define for0(i, n) for(int i = 0; i < (n); i++)
#define for1(i, n) for(int i = 1; i <= (n);i++)
using namespace std;
int n, ans[500 * 500 + 10], p, cnt;
vector<pair<int, int>>v;
bool b[510];
signed main() {
	cin >> n;
	for1(i, n) {
		cin >> p;
		ans[p] = i;
		v.push_back(make_pair(p, i));
	}
	p = 1;
	for1(i, n * n) {
		if (ans[i] == 0)cnt++;
		else {
			int u = ans[i] - 1;
			if (cnt < u) {
				cout << "No\n";
				return 0;
			}
			else {
				cnt -= u;
				for (int j = 0; j < u; j++) {
					if (ans[p] == 0) {
						ans[p] = ans[i];
					}
					else j--;
					p++;
				}
			}
		}
	}
	p = n * n; cnt = 0;
	for (int i = n * n; i >= 1; i--) {
		if (ans[i] == 0)cnt++;
		else if (!b[ans[i]]) {
			b[ans[i]] = 1;
			int u = n - ans[i];
			if (cnt < u) {
				cout << "No\n";
				return 0;
			}
			else {
				cnt -= u;
				for (int j = 0; j < u; j++) {
					if (ans[p] == 0) {
						ans[p] = ans[i];
					}
					else j--;
					p--;
				}
			}
		}
	}
	cout << "Yes\n";
	for1(i, n * n) { if (i > 1)printf(" "); cout << ans[i]; }printf("\n");
}