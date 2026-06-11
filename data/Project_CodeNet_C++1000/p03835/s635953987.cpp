#include<iostream>
using namespace std;

int main() {

	int K, S;
	cin >> K >> S;

	int x, y, z;
	int N1 = 0;
	int N2 = 0;
	int N3 = 0;

	for (x = 0; x <= K; x++) {
		z = S - 2 * x;
		if (z == x) N3++;
		else if (z >=0 && z <= K) N2++;

		for (y = x + 1; y <= K; y++) {
			z = S - x - y;
			if (z > y && z <= K) N1++;
		}
	}

	cout << 6 * N1 + 3 * N2 + N3;

	return 0;
}