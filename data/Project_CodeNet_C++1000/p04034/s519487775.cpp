#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define rrep(i,n) for(int i=1;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int inf = 0x7ffffff;
const int mod = 1000000007;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int> cur(100005, 1);
	vector<bool> res(100005, false);
	res[0] = true;
	rep(i, m) {
		int x, y;
		cin >> x >> y;
		x--; y--;
		cur[x]--;
		cur[y]++;
		if (res[x]) {
			if (cur[x] > 0) res[y] = true;
			else {
				res[x] = false;
				res[y] = true;
			}
		}
	}
	int ans = 0;
	rep(i, n) {
		if (res[i]) ans++;
	}
	cout << ans << endl;
	return 0;
}
