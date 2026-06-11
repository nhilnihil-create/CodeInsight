#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <iostream>
#include <sstream>
#include <cstring>
#include <numeric>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define F0(i,n) for (int i = 0; i < n; i++)
#define F1(i,n) for (int i = 1; i <= n; i++)
#define CL(a,x) memset(x, a, sizeof(x));
#define SZ(x) ((int)x.size())
const double eps = 1e-10;
const int MOD = 1000000007;
int i, j, k, m, n, l;
int ans;

int x[100001];
int y[100001];

int main() {
//	freopen("x.in", "r", stdin);
	cin >> n;
	F0(i, n) cin >> x[i];

	ans = 1;
	int k = n;
	int at = -1;
	F0(i, n) {
		y[i] = k;
		if (x[i] >= at + 2) {
			at += 2;
		}
		else {
			k--;
		}
	}
	k = 0;
	for (int i = n - 1; i >= 0; i--) {
		ans = (1LL * ans * (y[i] - k)) % MOD;
		k++;
	}
	cout << ans << endl;

	return 0;
}
