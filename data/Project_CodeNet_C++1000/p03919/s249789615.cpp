#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main() {
	int h, w;
	string s[30][30];
	cin >> h >> w;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> s[i][j];
			if (s[i][j] =="snuke") {
				cout << (char)(j + 65) << i + 1 << endl;
			}
		}
	}
}