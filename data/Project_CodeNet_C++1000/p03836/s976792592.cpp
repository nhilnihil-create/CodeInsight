#include"bits/stdc++.h"

#define rep(i, N) for(int i = 0;i < N;i++)
typedef long long ll;

using namespace std;

int main(void) {
	int sx, sy, tx, ty; cin >> sx >> sy >> tx >> ty;
	string ans;
	int H = ty - sy, W = tx - sx;

	cout << string(H, 'U') << string(W, 'R');
	cout << string(H, 'D') << string(W, 'L');
	cout << 'L' << string(H + 1, 'U') << string(W + 1, 'R');
	cout << 'D' << 'R';
	cout << string(H + 1, 'D') << string(W + 1, 'L');
	cout << 'U';

	return 0;
}