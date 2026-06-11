#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long A[4], D;

int main() {
	cin >> A[0] >> A[1] >> A[2] >> A[3] >> D;
	for (int i = 1; i <= 3; i++) A[i] = min(A[i], A[i - 1] * 2LL);
	cout << (D / 2LL) * A[3] + (D % 2LL) * A[2] << endl;
	return 0;
}