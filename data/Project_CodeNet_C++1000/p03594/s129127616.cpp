#include <iostream>
#include <string>
using namespace std;

int h, w, d;

int main() {
	cin >> h >> w >> d;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			int a = ((i + j + 1000) / d) % 2;
			int b = ((i - j + 1000) / d) % 2;
			cout << "RGBY"[a * 2 + b];
		}
		cout << endl;
	}
	return 0;
}