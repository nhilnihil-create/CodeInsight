#include <iostream>
#include <string>
using namespace std;

int main() {
	int H, W, RH, RW;
	string S;
	cin >> H >> W;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> S;
			if (S == "snuke") RH = i, RW = j;
		}
	}
	char X = RW + 65;
	cout << X << RH  + 1 << endl;
}