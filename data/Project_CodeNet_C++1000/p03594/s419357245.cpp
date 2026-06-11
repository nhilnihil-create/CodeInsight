#include <iostream>
#include <vector>
using namespace std;
int main(){
	int H, W, d;
	cin >> H >> W >> d;
	if (d % 2 == 1){
		for (int i = 0; i < H; i++){
			for (int j = 0; j < W; j++){
				if ((i + j) % 2 == 0){
					cout << 'R';
				} else {
					cout << 'Y';
				}
			}
			cout << endl;
		}
	} else {
		for (int i = 0; i < H; i++){
			for (int j = 0; j < W; j++){
				int i2, j2;
				if ((i + j) % 2 == 0){
					i2 = i;
					j2 = j;
				} else {
					i2 = i;
					j2 = j + 1;
				}
				int A = ((i2 + j2) / 2 % d + d) % d;
				int B = ((i2 - j2) / 2 % d + d) % d;
				if (A < d / 2){
					if (B < d / 2){
						cout << 'R';
					} else {
						cout << 'Y';
					}
				} else {
					if (B < d / 2){
						cout << 'G';
					} else {
						cout << 'B';
					}
				}
			}
			cout << endl;
		}
	}
}