#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int H, W, h, w;
	cin >> H >> W >> h >> w;
	if (H%h == 0 && W%w == 0) {
		cout << "No" << endl;
		return 0;
	}
	cout << "Yes" << endl;
	int base, rect;
	rect = (H / h)*(W / w);
	base = rect / (H*W - rect * h*w) + 1;
	for (int j = 1; j <= H; j++) {
		if (w == 1 && j % h == 0) {
			cout << -base * (w*h - 1) - 1;
		}
		else {
			cout << base;
		}
		for (int i = 2; i <= W; i++) {
			if (i%w == 0 && j%h == 0) {
				cout << " " << -base * (w*h - 1) - 1;
			}
			else {
				cout << " " << base;
			}
		}
		cout << endl;
	}
}