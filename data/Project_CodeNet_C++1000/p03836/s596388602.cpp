#include<bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mod 1000000007ll
const ll maxn = 9e18;
using namespace std;

void solve() {
	int sx, sy, tx, ty;
	cin >> sx >> sy >> tx >> ty;
	int dx = abs(sx - tx), dy = abs(sy - ty);
	cout << string(dx, 'R') << string(dy, 'U') << string(dx, 'L') << string(dy, 'D');
	cout << "D";
	cout << string(dx + 1, 'R') << string(dy + 1, 'U') << "L";
	cout << "U";
	cout << string(dx + 1, 'L') << string(dy + 1, 'D') << "R" << endl;
}

int main() {
	ios_base :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout.precision(35);
	solve();
	return 0;
	}
