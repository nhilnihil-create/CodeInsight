#include <iostream>
#include <string>

using namespace std;

int main() {
	string abc = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int h, w;
	cin >> h >> w;
	string s;
	int ii, jj;
	ii = jj = 0;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> s;
			if (s == "snuke") {
				ii = i+1;
				jj = j;
			}
		}
	}
	cout << abc[jj] << ii << endl;
	return 0;
}