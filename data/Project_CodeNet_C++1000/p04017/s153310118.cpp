#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;

int a[N], b[20][N];


int jump(int pos, int x) {
	for(int i = 19; i >= 0; i--) if((x >> i) & 1) {
		pos = b[i][pos];
	}
	return pos;
}

int main() {
	ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int L; cin >> L;
	for(int i = 1; i <= n; i++) {
		int l = upper_bound(a + 1, a + n + 1, a[i] + L) - a - 1;
		b[0][i] = l;
	}
	for(int i = 1; i < 20; i++) {
		for(int j = 1; j <= n; j++) {
			b[i][j] = b[i - 1][b[i - 1][j]];
		}
	}
	int q; cin >> q;
	for(int i = 1; i <= q; i++) {
		int p, q; cin >> p >> q; 
		if(p > q) {
			swap(p, q);
		}
		int l = 0, r = n;
		while(l < r) {
			int mid = (l + r) >> 1;
			if(jump(p, mid) >= q) {
				r = mid;
			} else l = mid + 1;
		}
		cout << r << endl;
	}
}