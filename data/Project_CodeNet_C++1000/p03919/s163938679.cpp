#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(int argc, char **argv) {
	int h, w;
	cin >> h >> w;
	vector<vector<string>> str(h, vector<string>(w));
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			cin >> str[i][j];
		}
	}
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			if(str[i][j] == "snuke") {
				cout << char(j + 'A') << i + 1 << endl;
			}
		}
	}
}
