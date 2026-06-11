#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <map>

using namespace std;

int main() {
	int N, K, X, Y;
	cin >> N >> K >> X >> Y;
	if (N > K) cout << K * X + (N - K) * Y << endl;
	else cout << N * X << endl;
	return 0;
}