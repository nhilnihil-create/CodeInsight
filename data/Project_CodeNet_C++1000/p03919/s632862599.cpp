#include <bits/stdc++.h>
using namespace std;

int main() {
	int H, W;  cin >> H >> W;
	string S;
	for (int i = 1; i <= H; i++) for (int j = 0; j < W; j++) {
		cin >> S;
		if (S == "snuke") {
			cout << (char)('A' + j) << i << endl;
		}
	}
}