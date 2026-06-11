#include <iostream>
#include <string>
using namespace std;

int main() {
	int N, l, r;
	int R = 0;
	cin >> N;
	for (int i = 0; N > i; i++) {
		cin >> l >> r;
		R += r - l + 1;
	}
	cout << R;
}