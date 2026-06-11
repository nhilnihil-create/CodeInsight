#include <cstdio>
#include <algorithm>
#include <unordered_set>
typedef long long ll;
using namespace std;
int h, w, n;
unordered_set<ll> board;
int cur_board[5][5];
ll ans[10];
int main() {
	scanf("%d%d%d", &h, &w, &n);
	ans[0] = (ll)(h - 2) * (w - 2);
	while(n--) {
		ll a;
		int b; scanf("%lld%d", &a, &b);
		if(board.find(a << 30 | b) != board.end()) continue;
		for(int di = -2; di <= 2; di++) for(int dj = -2; dj <= 2; dj++) {
			if(1 <= a + di && a + di <= h && 1 <= b + dj && b + dj <= w)
				cur_board[di + 2][dj + 2] = board.find((a + di) << 30 | (b + dj)) != board.end();
			else
				cur_board[di + 2][dj + 2] = 0;
		}
		for(int i = 0; i < 5; i++) for(int j = 0; j < 5; j++) {
			if(i > 0) cur_board[i][j] += cur_board[i - 1][j];
			if(j > 0) cur_board[i][j] += cur_board[i][j - 1];
			if(i > 0 && j > 0) cur_board[i][j] -= cur_board[i - 1][j - 1];
		}
		for(int di = -1; di <= 1; di++) for(int dj = -1; dj <= 1; dj++) {
			int a_ = a + di, b_ = b + dj;
			if(2 <= a_ && a_ <= h - 1 && 2 <= b_ && b_ <= w - 1) {
				int c = cur_board[di + 3][dj + 3];
				if(di >= 0) c -= cur_board[di][dj + 3];
				if(dj >= 0) c -= cur_board[di + 3][dj];
				if(di >= 0 && dj >= 0) c += cur_board[di][dj];
				ans[c]--;
				ans[c + 1]++;
			}
		}
		board.insert(a << 30 | b);
	}
	for(int i = 0; i < 10; i++) printf("%lld\n", ans[i]);
	return 0;
}
