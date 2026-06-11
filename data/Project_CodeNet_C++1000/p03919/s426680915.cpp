#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <array>
#include <vector>
#include <functional>
#define rep(i,n,m) for(int i=n;i<(int)(m);i++)
using namespace std;

int main() {
	int H, W, i, j, k, l;
	vector<vector<string>> str(26, vector<string>(26));
	string ans="",in,s = "snuke";
	char w;

	cin >> H >> W;


	for (k = 0; k < H; k++) {
		for (l = 0; l < W; l++) {
			cin >> str[k][l];
			
			}
		}

	for (k = 0; k < H; k++) {
		for (l = 0; l < W; l++) {
			in = str[k][l];
			if (in == s) {
				w = l + 65;
				cout << w << k + 1;
			}

		}
	}
	cout << endl;

	return 0;
}