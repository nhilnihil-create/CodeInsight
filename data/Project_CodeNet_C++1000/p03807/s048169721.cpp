#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
	int N;

	cin >> N;

	int odd = 0;

	for (int loop = 0; loop < N; ++loop) {
		long long inputval;
		cin >> inputval;

		if (0 != inputval % 2) {
			++odd;
		}
	}

	if (0 != odd % 2) {
		cout << "NO";
		return 0;
	} else {
		cout << "YES";
	}

	return 0;
}
