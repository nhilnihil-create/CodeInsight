#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	int H, W;
	cin >> H >> W;
	vector<vector<char>> A(H, vector<char>(W));
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> A[i][j];
		}
	}
	for (int i = 0; i < W + 2; i++) {
		cout << '#';
	}
	cout << endl;
	for (int i = 0; i < H; i++) {
		cout << '#';
		for (int j = 0; j < W; j++) {
			cout << A[i][j];
		}
		cout << '#' << endl;
	}
	for (int i = 0; i < W + 2; i++) {
		cout << '#';
	}
	cout << endl;
	return 0;
}