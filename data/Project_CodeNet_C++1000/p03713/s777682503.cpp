#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	long long h, w;
	cin >> h >> w;

	long long mn = 1010101010101010;
	for (long long i = 1; i < h; i++) {
		long long a = i * w;
		long long b = (h - i) * ((w + 1) / 2);
		long long c = (h - i) * (w / 2);
		long long tmp = max({ a, b, c }) - min({ a, b, c });
		mn = min(mn, tmp);
	}
	for (long long i = 1; i < h - 1; i++) {
		long long a = i * w;
		long long b = (h - i) / 2 * w;
		long long c = (h - i + 1) / 2 * w;
		long long tmp = max({ a, b, c }) - min({ a, b, c });
		mn = min(mn, tmp);
	}
	for (long long i = 1; i < w; i++) {
		long long a = i * h;
		long long b = (w - i) * ((h + 1) / 2);
		long long c = (w - i) * (h / 2);
		long long tmp = max({ a, b, c }) - min({ a, b, c });
		mn = min(mn, tmp);
	}
	for (long long i = 1; i < w - 1; i++) {
		long long a = i * h;
		long long b = (w - i) / 2 * h;
		long long c = (w - i + 1) / 2 * h;
		long long tmp = max({ a, b, c }) - min({ a, b, c });
		mn = min(mn, tmp);
	}
	cout << mn << endl;

	return 0;
}