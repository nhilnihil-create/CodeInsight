#include <iostream>
using namespace std;

int main() {
	int X, out;
	cin >> X;
	for (int i = 1; ; i++) {
		if (i * (i - 1) / 2 < X && X <= i * (i + 1) / 2) {
			out = i;
			break;
		}
	}
	cout << out << endl;
}