#include<iostream>
#include<iomanip>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<string>
#include<algorithm>
#include<math.h>
#include<unordered_set>
using namespace std;

const int MAX = 500;
int H, W, d;

char getColor(int x, int y) {
	x = (x + W) / d;
	y = (y + H) / d;
	if (y & 1) {
		if (x & 1)return 'R';
		else return 'G';
	}
	else {
		if (x & 1)return 'B';
		else return 'Y';
	}
}

int main() {
	cin >> H >> W >> d;

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			int y = i + j;
			int x = i - j;
			cout << getColor(x, y);
		}
		cout << endl;
	}
	return 0;
}