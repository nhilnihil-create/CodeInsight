#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int main() {
	int H, W;
	cin >> H >> W;
	vector<vector<char>> C(H, vector<char>(W));
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> C[i][j];
		}
	}
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cout << C[i][j];
		}
		cout << endl;
		for (int j = 0; j < W; j++) {
			cout << C[i][j];
		}
		cout << endl;
	}
	return 0;
}