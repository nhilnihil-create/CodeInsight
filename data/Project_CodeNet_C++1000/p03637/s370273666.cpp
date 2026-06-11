#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
	int N;

	cin >> N;

	int A[3] = {0};

	for(int loop = 0; loop < N; ++loop) {
		long long int a;
		cin >> a;

		if (0 == a % 4) {
			++A[0];
		} else if (2 == a % 4) {
			++A[2];
		} else {
			++A[1];
		}
	}

	if (A[0] >= A[1]) {
		cout << "Yes";
	} else if ((A[0] == A[1] - 1) && 0 ==A[2]) {
		cout << "Yes";
	} else {
		cout << "No";
	}

	return 0;
}
