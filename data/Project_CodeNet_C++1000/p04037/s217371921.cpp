#include"bits/stdc++.h"
#include<cassert>
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
const int mod = 1000000007;
const int inf = 1ll << 61;
typedef pair<int, int> P;
typedef pair<int,P>PP;
int a[100006];

signed main() {
	int n; cin >> n;
	rep(i, n)cin >> a[i];
	sort(a, a + n);
	reverse(a, a + n);
	int l = -1, r = -1;
	rep(i, n) {
			if (i + 1 > a[i]) {
				l = a[i - 1] - i;
				r = 0;
				for (int j = i; j < n; j++)if (i == a[j])r++;
				break;
			}
		}
	if (l == -1 && r == -1) {
		l = 0;
		r = a[n - 1] - n;
	}

	if (l % 2 == 0 && r % 2 == 0)puts("Second");
	else puts("First");
}