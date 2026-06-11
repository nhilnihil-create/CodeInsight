#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <stdio.h>
using namespace std;
#define int long long
int BIG = 1000;
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int H, W, K;
	cin >> H >> W >> K;
	vector<string> s(H);
	vector < vector<int> >res(H, vector<int>(W, -1));
	vector < vector<int> >m(H, vector<int>(W, 0));
	int a;
	if (K % 2 == 1) {
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				res[i][j] = (i + j) % 2;
			}
		}
	}
	else {
		//K /= 2;
		BIG *= 2 * K;
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				res[i][j] = (((i + j) % (2 * K)) / K) * 2 + (((i - j + BIG) % (2 * K)) / K);
			}
		}
	}
	char  x[4] = { 'R','Y','G','B' };
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cout << x[res[i][j]];
		}
		cout << endl;

	}

}