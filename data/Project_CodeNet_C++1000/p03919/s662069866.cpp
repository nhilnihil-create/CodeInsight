#include <iomanip>
#include <string>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>

using namespace std;
int main() {
	string s[30][30], a = "snuke";
	char b;
	int h, w, c;
	cin >> h >> w;
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			cin >> s[i][j];
			if (s[i][j] == a) {
				b = 'A' + j - 1;
				c = i;
			}
		}
	}
	cout << b << c << endl;
	return 0;
}