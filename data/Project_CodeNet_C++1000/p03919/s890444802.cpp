#include <iostream>
#include <string>

using namespace std;


int main() {
	int h,w;

	cin >> h >> w;

	for(int y = 0; y < h; y++) {
		for(int x = 0; x < w; x++) {
			string str;
			cin >> str;
			if (str == "snuke") {
				cout << (char) (x + 'A') << y + 1 << endl;
			}
		}
	}

	return 0;
}