#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

const int N = 100 * 1000 + 5;

pair <int, int> a[N];
long long pos[N];
int main() {
	long long x = 0;
	int n, l, t;
	cin >> n >> l >> t;
	for (int i = 0; i < n; i++) {
		cin >> a[i].first >> a[i].second;
		if (a[i].second == 1) {
			pos[i] = a[i].first + t;
			x += pos[i] / l;
			pos[i] %= l;
		}
		else {
			pos[i] = a[i].first - t;
			if (pos[i] < 0) {
				x -= (-pos[i] - 1) / l + 1;
			}
			pos[i] += 1ll * l * N;
			pos[i] %= l;
		}
	//	cout << i << " " << pos[i] << endl;
	}
	sort(pos, pos + n);
//	cout << x << endl;
	x += 1ll * n * t * 1000;
	x += 1ll * n * n;
	x %= n;
	for (int i = 0; i < n; i++) {
		cout << pos[(i + x) % n] << endl;
	}
	return 0;
}
