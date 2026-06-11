#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
#include <iomanip>
#include <queue>
#include <numeric>


using namespace std;


int main() {
	int a, N, MIN, MAX, free = 0, ans = 0;
	bool color[8];
	
	for (int i = 0; i < 8; i++) {
		color[i] = false;
	}

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> a;
		if (a >= 3200) {
			free++;
			continue;
		}

		for (int i = 0; i <8; i++) {
			if (a < 400 * (i + 1)) {
				color[i] = true;
				break;
			}
		}
	}

	for (int i = 0; i < 8; i++) {
		if (color[i]) {
			ans++;
		}
	}

	if (ans == 0) {
		MIN = 1;
		MAX = free;
	}
	else {
		MIN = ans;
		MAX = ans + free;
	}

	cout << MIN << " " << MAX;

	return 0;
}
