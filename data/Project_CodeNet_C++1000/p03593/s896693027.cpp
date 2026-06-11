#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	int h, w;
	cin >> h >> w;
	vector<string> s(h);
	for (int i = 0; i < h; i++) {
		cin >> s[i];
	}

	int a[26] = {};
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			a[s[i][j] - 'a']++;
		}
	}

	int sum4 = 0, sum2 = 0;
	for (int i = 0; i < 26; i++) {
		int tmp = a[i] / 4;
		a[i] -= tmp * 4;
		sum4 += tmp;
		sum2 += a[i] / 2;
	}
	if ((h / 2) * (w / 2) <= sum4) {
		sum4 -= (h / 2) * (w / 2);

		int t = 0;
		if (h % 2 == 1) {
			t += w / 2;
		}
		if (w % 2 == 1) {
			t += h / 2;
		}
		if (t <= sum2 + sum4 * 2) {
			cout << "Yes" << endl;
		} else {
			cout << "No" << endl;
		}
	} else {
		cout << "No" << endl;
	}

	return 0;
}