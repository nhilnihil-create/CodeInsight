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
	int sx, sy, tx, ty;
	cin >> sx >> sy >> tx >> ty;
	int dx = tx - sx;
	int dy = ty - sy;
	string s;
	rep(i, dx) s += 'R';
	rep(i, dy) s += 'U';
	rep(i, dx) s += 'L';
	rep(i, dy) s += 'D';
	s += 'D';
	rep(i, dx + 1) s += 'R';
	rep(i, dy + 1) s += 'U';
	s += 'L';
	s += 'U';
	rep(i, dx + 1) s += 'L';
	rep(i, dy + 1) s += 'D';
	s += 'R';
	cout << s << endl;
	return 0;
}
