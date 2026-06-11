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
	int n, m;
	cin >> n >> m;
	vector<string> a(n), b(m);
	rep(i, n) cin >> a[i];
	rep(i, m) cin >> b[i];
	for (int di = 0; di <= n - m; ++di) {
		for (int dj = 0; dj <= n - m; ++dj) {
			bool ok = true;
			rep(i, m) {
				rep(j, m) {
					if (b[i][j] != a[i + di][j + dj]) ok = false;
				}
			}
			if (ok) {
				cout << "Yes" << endl;
				return 0;
			}
		}
	}
	cout << "No" << endl;
	return 0;
}
