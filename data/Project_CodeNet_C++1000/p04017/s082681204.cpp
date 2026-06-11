#include <bits/stdc++.h>
using namespace std;

int x[110000];
int nxt[20][110000];

inline int calc(int L, int n) {
	for (int i = 0; i < 20; i++) if (n & (1 << i)) L = nxt[i][L];
	return L;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> x[i];
	int L; cin >> L;
	for (int i = 1; i <= n; i++) {
		nxt[0][i] = upper_bound(x + 1, x + n + 1, x[i] + L) - x - 1;
	}
	for (int i = 1; i < 20; i++) for (int j = 1; j <= n; j++) nxt[i][j] = nxt[i - 1][nxt[i - 1][j]];
	int Q; cin >> Q;
	for (int i = 1; i <= Q; i++) {
		int L, R; cin >> L >> R;
		if (R < L) swap(L, R);
		int st = 0, en = 200000;
		while (en - st > 1) {
			int mid = st + en >> 1;
			if (calc(L, mid) >= R) en = mid;
			else st = mid;
		}
		cout << en << "\n";
	}
	return 0;
}

