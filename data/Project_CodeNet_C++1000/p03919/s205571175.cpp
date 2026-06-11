#include "bits/stdc++.h"
using namespace std;
string S[26][26];
int main() {
	int H, W;
	cin >> H >> W;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) cin >> S[i][j];
	}
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (S[i][j] == "snuke") {
				printf("%c%d\n", 'A' + j, i + 1);
				return 0;
			}
		}
	}
}