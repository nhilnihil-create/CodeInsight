#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int H, W, h, w;
	cin >> H >> W >> h >> w;
	if(H % h == 0 && W % w == 0) {
		cout << "No";
		return 0;
	}
	cout << "Yes\n";
	int rem = H * W - (H / h * h) * (W / w * w);
	int x = (H / h) * (W / w);
	x = (x + rem - 1) / rem;
	x++;
	for(int i = 1; i <= H; i++, cout << endl)
		for(int j = 1; j <= W; j++)
			cout << (i % h == 0 && j % w == 0? (-h) * w * x - 1 + x: x) << ' ';
}
