#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define rrep(i,n) for(int i=1;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define maxs(a, b) a = max(a, b)
#define mins(a, b) a = min(a, b)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const ll linf = (1ll << 61);
const int inf = 1001001001;
const int mod = 1000000007;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> col(9);
	rep(i, n) {
		int a;
		cin >> a;
		if (a >= 3200) a = 3200;
		col[int(a / 400)]++;
	}
	int ans = 0;
	rep(i, 8) ans += (col[i] >= 1);
	if (ans == 0) {
		printf("%d %d\n", col[8] >= 1, col[8]);
		return 0;
	}
	printf("%d ", ans);
	ans += col[8];
	printf("%d\n", ans);
	return 0;
}
