#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int H, W;
	cin >> H >> W;
	vector<int> b(26);
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			char a;
			cin >> a;
			b[a - 'a']++;
		}
	}
	int c = H % 2 * W + W % 2 * H;
	if (H % 2 && W % 2) c--;
	if (c % 2) {
		vector<int>::iterator d = find_if(b.begin(), b.end(), [](int& a) { return a % 2; });
		if (d == b.end()) {
			cout << "No";
			return 0;
		}
		(*d)--;
		c--;
	}
	if (find_if(b.begin(), b.end(), [](int& a) { return a % 2; }) != b.end()) {
		cout << "No";
		return 0;
	}
	while (c != 0) {
		vector<int>::iterator d = find_if(b.begin(), b.end(), [](int& a) { return a % 4; });
		if (d == b.end()) {
			vector<int>::iterator e = find_if(b.begin(), b.end(), [](int& a) { return a != 0; });
			*e -= 2;
			c -= 2;
		}
		else {
			*d -= 2;
			c -= 2;
		}
	}
	c = H % 2 * W + W % 2 * H;
	if (H % 2 && W % 2) c--;
	if (H * W == c) cout << "Yes";
	else {
		if (find_if(b.begin(), b.end(), [](int& a) { return a % 4; }) != b.end()) cout << "No";
		else cout << "Yes";
	}
}