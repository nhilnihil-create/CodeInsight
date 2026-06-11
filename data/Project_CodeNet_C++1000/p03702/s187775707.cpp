#include <iostream>
#include <cmath>
using namespace std;


const int N = 100 * 1000 + 5;
const int inf = 1000 * 1000 * 1000 + 7;
int n, a, b;

int h[N];
bool isval(long long x) {
	long long y = 0;
	for (int i = 0; i < n; i++) {
		if (h[i] > 1ll * x * b) {
			y += (long long) ceil((long double) (h[i] - b * x) / (a - b));
//			cout << "73 " << x << " " << i << " " << (long long) ceil((long double) (h[i] - b * x) / (a - b)) << endl;
		}
	}
//	cout << x << " " << y << endl;
	return y <= x;
}
int main() {
	cin >> n >> a >> b;
	for (int i = 0; i < n; i++) {
		cin >> h[i];
	}
	int dw = 0, up = inf;
	while (up - dw > 1) {
		int md = (dw + up) / 2;
		if (isval(md))
			up = md;
		else
			dw = md;
	}
	cout << up << endl;
	return 0;
}
