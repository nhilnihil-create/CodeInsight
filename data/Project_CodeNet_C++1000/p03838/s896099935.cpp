#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define dup(x,y) (((x)+(y)-1)/(y))
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> pii;
const double EPS = 1e-10;
const int INF = 1e9;
const ll LINF = 1e15;
const int MOD = 1000000007;
const double PI = acos(-1);
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int main() {
	ll x, y;
	cin >> x >> y;
	if (x == 0) {
		if (y < 0) cout << 1 + abs(y) << endl;
		else cout << y << endl;
	} else if (y == 0) {
		if (x < 0) cout << abs(x) << endl;
		else cout << 1 + x << endl;
	} else if ((x > 0 && y > 0) || (x < 0 && y < 0)) {
		if (x <= y) {
			cout << abs(y - x) << endl;
		} else {
			cout << abs(y - x) + 2 << endl;
		}
	} else {
		cout << 1 + abs(abs(x) - abs(y)) << endl;
	}
}