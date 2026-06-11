#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
int main() {
	int x,count=0;
	cin >> x;
	for (int i = 1;; i++) {
		count += i;
		if (count >= x) {
			cout << i << endl;
			getchar();
			getchar();
			return 0;
		}
	}
}