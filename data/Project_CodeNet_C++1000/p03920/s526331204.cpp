#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	int n;
	int a,c;
	
	cin >> n;

	for (int i = 1;; ++i) {
		if (n <= i*(i + 1) / 2) {
			a = i;
			break;
		}
	}

	c = a*(a + 1) / 2 - n;
	for (int i = 1; i <= a; ++i) {
		if (i !=c) {
			cout << i << endl;
		}
	}
	return 0;
}