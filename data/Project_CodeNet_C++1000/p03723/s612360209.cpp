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
const ll linf = 1001002003004005006ll;
const int inf = 1001001001;
const int mod = 1000000007;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	vector<int> a(3);
	rep(i, 3) cin >> a[i];
	bool elf = true;
	rep(i, 3) if (a[i] % 2 != 0) elf = false;
	if (!elf) {
		cout << 0 << endl;
		return 0;
	}
	if (a[0] == a[1] && a[1] == a[2]) {
		cout << -1 << endl;
		return 0;
	}
	int ans = 1;
	rep(ri, 1000000) {
		int b = (a[1] + a[2]) / 2;
		int c = (a[0] + a[2]) / 2;
		int d = (a[0] + a[1]) / 2;
		bool ok = true;
		a[0] = b, a[1] = c, a[2] = d;
		rep(i, 3) if (a[i] % 2 != 0) ok = false;
		if (!ok) break;
		ans++;
	}
	cout << ans << endl;
	return 0;
}