#include"bits/stdc++.h"
using namespace std;
#define int long long
#define con continue
#define rep(i,n) for(int i=0;i<n;i++)
const long long mod = 1000000007;
const long long inf = 1ll<<61;
typedef pair<int, int> P;
typedef pair<P, int> PP;
typedef pair<int, PP> PPP;
struct edge { int to; int to2; int cost; };

int a[100006], b[100006];
int ubit[35];
int hbit(int a) {
	int res = -1;
	while (a) {
		res++; a >>= 1;
	}
	return res;
}

signed main() {
	int n, k; cin >> n >> k;
	rep(i, n)cin >> a[i] >> b[i];
	int K = hbit(k);
	int sum = 0;
	for (int i = K; i >= 0; i--) {
		if (k&(1 << i)) {
			for (int j = K; j >= 0; j--) {
				if (i == j)ubit[j] = 0;
				else if (i < j)ubit[j] = k & 1 << j ? 1 : 0;
				else ubit[j] = 1;
			}
		}
		else {
			rep(j, K + 1)ubit[j] = k&(1 << j) ? 1 : 0;
		}
			int res = 0;
			rep(j, n) {
				int flg = 0;
				if (a[j] > k)flg++;
				rep(l, K + 1) {
					if ((a[j] & (1 << l)) && !ubit[l])flg++;
				}
				if (!flg)res += b[j];
			}
			sum = max(sum, res);
	}

	rep(j, K + 1)ubit[j] = k&(1 << j) ? 1 : 0;
	int res = 0;
	rep(j, n) {
		int flg = 0;
		if (a[j] > k)flg++;
		rep(l, K + 1) {
			if ((a[j] & (1 << l)) && !ubit[l])flg++;
		}
		if (!flg)res += b[j];
	}
	sum = max(sum, res);
	cout << sum << endl;
}