#include <bits/stdc++.h>
using namespace std;
int H, W; string s;
int main() {
	cin >> H >> W;
	for(int i = 0; i < H; i++) {
		for(int j = 0; j < W; j++) {
			cin >> s;
			if(s == "snuke") cout << (char)(j + 65) << i + 1 << endl;
		}
	}
}