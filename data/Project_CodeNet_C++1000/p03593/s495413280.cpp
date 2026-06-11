#include <bits/stdc++.h>
using namespace std;

int h, w;
int c[26], two, one;

int main() {
	cin >> h >> w;
	for (int i = 0; i < h; i++) {
		string s;
		cin >> s;
		for (int i = 0; i < w; i++)
			c[s[i] - 'a']++;
	}
	for (int i = 0; i < 26; i++) {
		c[i] %= 4;
		two += c[i] / 2;
		c[i] %= 2;
		one += c[i];
	}
	cout
			<< (two <= h / 2 * (w & 1) + w / 2 * (h & 1) && one == (h & w & 1) ?
					"Yes" : "No") << endl;

}
