#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <functional>
#include <cmath>
#include <iomanip>
using namespace std;

int DP[100][100];

int main() {
	long long X, Y; cin >> X >> Y;

	/*
	for (int i = 0; i < 100; i++)for (int j = 0; j < 100; j++)DP[i][j] = -1;

	vector<int>pos(100);
	while (1) {
		for (int j = 0; j < 100; j++) {
			for (int i = pos[j]; i < 100; i++) {
				int flag = 0;
				for (int k = 1; flag != -1 && k <= i / 2; k++) {
					if (DP[i - 2 * k][j + k] == -1)flag = -1;
					else if (!DP[i - 2 * k][j + k])flag = 1;
				}
				for (int k = 1; flag != -1 && k <= j / 2; k++) {
					if (DP[i + k][j - 2 * k] == -1)flag = -1;
					else if (!DP[i + k][j - 2 * k])flag = 1;
				}

				if (flag == -1) break;
				else DP[i][j] = DP[j][i] = flag;
				pos[j] = i + 1;
			}
		}
		if (pos[99] == 100)break;
	}

	for (int i = 0; i < 100; i++) {
		for (int j = 0; j <= i; j++) {
			cout << i << " " << j << " " << DP[i][j] << endl;
		}
	}
	*/

	if (abs(X - Y) <= 1)cout << "Brown" << endl;
	else cout << "Alice" << endl;

	return 0;
}