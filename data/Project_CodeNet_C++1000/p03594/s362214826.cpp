#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <list>
#include <stack>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

#define int long long
#define MOD7 1000000007
#define MOD9 1000000009

#define rep(i, n) for (int i = 0; i < (n); i++)
#define itrep(i, a) for (auto i = (a).begin(); i != (a).end(); i++)
#define REP(i, a, n) for (int i = (a); i <= (n); i++)
#define all(a) (a).begin(), (a).end()
#define mp(a, b) make_pair((a), (b))

using namespace std;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };

template<class T> void inputVector(vector<T>& v, int n) {
    v.resize(n);
    for (int i = 0; i < v.size(); i++) cin >> v[i];
}

int H, W, d;
int board[510][510];
bool pattern[1000][1000];

bool inBoard(int x, int y) {
	return x >= 0 && x < W && y >= 0 && y < H;
}

signed main() {
	cin >> H >> W >> d;

	if (d % 2) {
		rep(y, H) {
			rep(x, W) cout << ((x + y) % 2 ? 'R' : 'Y');
			cout << endl;
		}
		return 0;
	}

	int pH = d - 1;
	int pW = d;
	rep(y, pH) rep(x, pW) pattern[y][x] = true;
	rep(y, pH) {
		int num = abs(pH / 2 - y);
		rep(i, num) {
			pattern[y][i] = false;
			pattern[y][pW - i - 1] = false;
		}
	}

	int cnt = 0;
	for (int ty = - H - 2 * d; ty < H + 2 * d; ty += d / 2) {
		int tx = -d;
		if (cnt % 2) tx -= d / 2;

		int color = cnt % 2 ? 0 : 2;
		color += (cnt / 2) % 2 ? 0 : 1;
		while (tx < W) {
			rep(py, pH) rep(px, pW) {
				if (!inBoard(tx + px, ty + py)) continue;
				if (!pattern[py][px]) continue;
				board[ty + py][tx + px] = color;
			}

			color += color % 2 ? -1 : 1;
			tx += pW;
		}

		cnt++;
	}

	char ch[4] = { 'R', 'Y', 'G', 'B' };
	rep(y, H) {
		rep(x, W) cout << ch[board[y][x]];
		cout << endl;
	}

    return 0;
}
