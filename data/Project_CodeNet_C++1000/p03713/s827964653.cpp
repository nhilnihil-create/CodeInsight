#include <bits/stdc++.h>

using namespace std;

int main() {

	long long h, w;
	cin >> h >> w;

	long long ans = 1000000000000;
	long long h1, h2, h3;
	long long w1, w2, w3;
	long long s1, s2, s3;

	if (h == 2 && w == 2) {
		cout << 1 << endl;
		return 0;
	}

	//pattern1
	if (h != 2) {
		h1 = h / 3;
		h2 = (h - h1) / 2;
		h3 = h - h1 - h2;

		s1 = w * h1;
		s2 = w * h2;
		s3 = w * h3;

		ans = min(ans, max(s1, max(s2, s3)) - min(s1, min(s2, s3)));

		//pattern2

		for (long long i = 1; i <= h - 1; i++) {
			h1 = i;
			h2 = i;
			h3 = h - i;
			w1 = w / 2;
			w2 = w - w1;
			w3 = w;
			s1 = h1 * w1;
			s2 = h2 * w2;
			s3 = h3 * w3;
			ans = min(ans, max(s1, max(s2, s3)) - min(s1, min(s2, s3)));
		}
	}

	if (w != 2) {
		long tmp;
		tmp = h;
		h = w;
		w = tmp;

		//pattern1
		h1 = h / 3;
		h2 = (h - h1) / 2;
		h3 = h - h1 - h2;

		s1 = w * h1;
		s2 = w * h2;
		s3 = w * h3;

		ans = min(ans, max(s1, max(s2, s3)) - min(s1, min(s2, s3)));

		//pattern2

		for (long i = 1; i <= h - 1; i++) {
			h1 = i;
			h2 = i;
			h3 = h - i;
			w1 = w / 2;
			w2 = w - w1;
			w3 = w;
			s1 = h1 * w1;
			s2 = h2 * w2;
			s3 = h3 * w3;
			ans = min(ans, max(s1, max(s2, s3)) - min(s1, min(s2, s3)));
		}
	}




	cout << ans << endl;
}