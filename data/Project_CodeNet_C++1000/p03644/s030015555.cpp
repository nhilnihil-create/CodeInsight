#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
#include <utility>
using namespace std;
int main() {
	int N;
	int p=1;
	int cnt = 0;
	cin >> N;
	for (int i = 0; i < 100000; i++) {
		if (2 * p <= N) {
			cnt++;
			p = 2 * p;
		}
	}
	cout << p << endl;
	return 0;
}
