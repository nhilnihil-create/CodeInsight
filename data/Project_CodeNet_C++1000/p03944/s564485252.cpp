#include <iostream>
using namespace std;
int main(){
	int W, H, N;
	int count = 0;
	int S[100][100] = { 0 }; int x[100]; int y[100]; int a[100];
	cin >> W >> H >> N;
	for (int i = 0;i < N;i++) cin >> x[i] >> y[i] >> a[i];
	for (int i = 0;i < N;i++) {
		if (a[i] == 1) {
			for (int k = 0;k < H;k++) {
				for (int j = 0;j < x[i];j++)
					S[k][j] = 1;
			}
		}
		if (a[i] == 2) {
			for (int k = 0;k < H;k++) {
				for (int j = x[i];j < W;j++)
					S[k][j] = 1;
			}
		}
		if (a[i] == 3) {
			for (int k = 0;k < y[i];k++) {
				for (int j = 0;j < W;j++)
					S[k][j] = 1;
			}
		}
		if (a[i] == 4) {
			for (int k = y[i];k < H;k++) {
				for (int j = 0;j < W;j++)
					S[k][j] = 1;
			}
		}
	}
		for(int k=0;k<H;k++){
			for (int j = 0;j < W;j++)
				if (S[k][j] == 0) count++;
	}
		cout << count;
}