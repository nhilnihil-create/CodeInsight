#include <bits/stdc++.h>

using namespace std;

int main() {
	int h, w;
	cin >> h >> w;
	string s = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			string a;
			cin >> a;
			if (a == "snuke") {
				cout << s[j] << i+1 << endl;
				return 0;
			}
		}
	}
}