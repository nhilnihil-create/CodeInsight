#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(int argc, char **argv) {
	int h, w;
	cin >> h >> w;
	string s;
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			cin >> s;
			if(s == "snuke") {
				cout << char(j + 'A') << i + 1 << endl;
			}
		}
	}
}
