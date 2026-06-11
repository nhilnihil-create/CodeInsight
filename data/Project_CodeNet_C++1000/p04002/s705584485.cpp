#include<iostream>
#include<algorithm>
#include<set>
#define int long long
#define for0(i, n) for(int i = 0; i < (n); i++)
#define mp make_pair
using namespace std;
typedef pair<int, int> P;
set<P>s; multiset<P>ms;
int h, w, n, ans[20];
signed main() {
	cin >> h >> w >> n;
	while (n--) {
		int x, y; cin >> x >> y;
		for (int i = -1; i <= 1; i++)for (int j = -1; j <= 1; j++) if (1 < x + i && x + i < h && 1 < y + j && y + j < w) {
			s.insert(mp(x + i, y + j));
			ms.insert(mp(x + i, y + j));
		}
	}
	ans[0] = (h - 2) * (w - 2);
	for (P p1 : s) {
		ans[0]--; ans[ms.count(p1)]++;
	}
	for0(i, 10)cout << ans[i] << endl;
}