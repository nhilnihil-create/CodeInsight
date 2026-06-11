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
	int H, W, i, j;
	string str[26][26];
	string s = "snuke";
	char w;

	cin >> H >> W;


	for (i = 0; i < H; i++) {
		for (j= 0; j < W; j++) {
			cin >> str[i][j];

		}
	}

	for (i = 0; i < H; i++) {
		for (j = 0; j < W; j++) {
			if (str[i][j] == s) {
				w = j + 65;
				cout << w << i + 1;
			}
		}
	}
	cout << endl;

	return 0;
}