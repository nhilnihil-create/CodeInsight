#include<cstdio>
#include<iostream>
#include<string>

using namespace std;

int main(void) {

	bool br = false;
	char tmp;
	int h, w;
	string s;

	cin >> h >> w;

	for (int k = 0; k < h; k++) {
		if (br == true)break;
		for (int l = 0; l < w; l++) {
			cin >> s;
			tmp = l+65;
			if (s == "snuke") {
				cout << tmp << k + 1 << "\n";
				br = true;
				break;
			}
		}
	}
	

	return 0;
}