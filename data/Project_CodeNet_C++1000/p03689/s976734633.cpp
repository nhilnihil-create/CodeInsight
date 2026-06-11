#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const double PI = 3.141592653589793238;
const double EPS = 1e-10;
int s[501];
int main() {
	int H, W, h, w;
	cin >> H >> W >> h >> w;
	if (H%h == 0 && W%w == 0) {
		cout << "No" << endl;
		return 0;
	}
	cout << "Yes" << endl;
	if (W%w) {
		s[0] = 0;
		for (int i = w; i <= W; i+=w) {
			s[i] = s[i - w] - 1;
		}
		for (int i = 1; i < w; i++) {
			s[i] = W;
			for (int j = i + w; j <= W; j += w) s[j] = s[j - w] - 1;
		}
		for (int i = 1; i <= H; i++) {
			for (int j = 1; j <= W; j++) {
				int A = s[j] - s[j - 1];
				cout << A << " ";
			}
			cout << endl;
		}
	}
	else {
		s[0] = 0;
		for (int i = h; i <= H; i += h) {
			s[i] = s[i - h] - 1;
		}
		for (int i = 1; i < h; i++) {
			s[i] = H;
			for (int j = i + h; j <= H; j += h) s[j] = s[j - h] - 1;
		}
		for (int i = 1; i <= H; i++) {
			for (int j = 1; j <= W; j++) {
				int A = s[i] - s[i - 1];
				cout << A << " ";
			}
			cout << endl;
		}
	}
}
