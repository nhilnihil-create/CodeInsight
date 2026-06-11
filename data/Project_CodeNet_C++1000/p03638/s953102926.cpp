#include "bits/stdc++.h"
using namespace std;

int main() {
	int H, W, N;
	cin >> H >> W >> N;
	vector<int>A(N); 
	vector<vector<int>> data(H, vector<int>(W));
	for (int i = 0;i<N;++i) {
		cin >> A[i];
	}	
	int count = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0;j<A[i];++j) {
			int x = count / W;
			int y = count %W;
			if (1 == x%2) {
				y = W - 1 - y;
			}
			data[x][y]= i + 1;
			count++;
		}
	}
	for (int i = 0;i<H;++i) {
		for (int j = 0;j<W;++j) {
			if (0 != j) {
				cout <<" ";
			}
			cout << data[i][j];
		}
		cout << endl;
	}
	return 0;
}