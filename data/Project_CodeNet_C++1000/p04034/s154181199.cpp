#include"bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
const ll INF = 1LL << 60;

int main() {
	int n, m, red = 0, x, y, cnt = 0;
	cin >> n >> m;
	vector<int>ball(n, 1);
	vector<bool>visit(n, false);
	visit[red] = true;

	rep(i, m) {
		cin >> x >> y;
		x--, y--;
		if (visit[x]) {
			visit[y] = true;
		}
		ball[x]--; ball[y]++;
		if (visit[x] && ball[x] == 0)visit[x] = false;
	}
	rep(i, n) {
		if (visit[i] && 1 <= ball[i])cnt++;
	}
	cout << cnt << endl;
	return 0;
}

