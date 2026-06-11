#include<bits/stdc++.h>
using namespace std;
const long long inf = 1000000000000000000;
int main() {
	int h, w;
	cin >> h >> w;
	string a[26][26];
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> a[i][j];
			if (a[i][j] == "snuke") {
				char b = 'A' + j;
				cout << b << i + 1;
				break;
			}
		}
	}
}