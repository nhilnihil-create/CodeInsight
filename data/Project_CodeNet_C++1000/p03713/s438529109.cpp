#include <iostream>
#include <algorithm>
using namespace std;
long long INF = 1001001001001;

long long score(long long a, long long b, long long c) {
	return max({a, b, c}) - min({a, b, c});
}

int main() {
	long long h, w;
	cin >> h >> w;
	long long ans = INF;
	if (h >= 3) ans = min(ans, (h+2)/3*w - h/3*w);
	if (w >= 3) ans = min(ans, (w+2)/3*h - w/3*h);
	for (long long a = 1; a < w; a++) {
		long long now = score(h*a, h/2*(w-a), (h+1)/2*(w-a));
		ans = min(ans, now);
	}
	for (long long a = 1; a < h; a++) {
		long long now = score(a*w, w/2*(h-a), (w+1)/2*(h-a));
		ans = min(ans, now);
	}
	cout << ans << endl;
	return 0;
}