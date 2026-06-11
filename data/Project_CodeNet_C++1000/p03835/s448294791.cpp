#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
int main() {
	int k;
	int s;
	cin >> k >> s;

	int x;
	int y;
	int z;

	int count;
	count = 0;
	for (x = 0; x <= k; x++) {
		for (y = 0; y <= k; y++) {
			if ((s - x - y <= k) && (s - x - y >= 0)) count++;
		}
	}

	cout << count << endl;

	return 0;
}