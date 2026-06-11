#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define rrep(i,n) for(int i=1;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define dunk(a) cout << (a) << "\n"
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int inf = 1001001001;
const int mod = 1000000007;

int a[10001];
int ans[105][105];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int h, w, n;
	cin >> h >> w >> n;
	rep(i, n) {
		int b; cin >> b;
		a[i] = b;
	}
	int cell = 0;
	for (int i = 0; i < h; ++i) {
		if (i % 2 == 0) {
			rep(j, w) {
				ans[i][j] = cell + 1;
				a[cell]--;
				if (a[cell] == 0) cell++;
			}
		}
		else {
			for (int j = w - 1; j >= 0; --j) {
				ans[i][j] = cell + 1;
				a[cell]--;
				if (a[cell] == 0) cell++;
			}
		}
	}
	rep(i, h)rep(j, w) cout << ans[i][j] << (j == w - 1 ? "\n" : " ");
	return 0;
}