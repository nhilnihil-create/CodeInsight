#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
#include <iomanip>
#include <queue>


using namespace std;


int main() {

	long long int ans = 1, div = pow(10, 9) + 7;
	int N;

	cin >> N;

	for (int i = 1; i <= N; i++) {
		ans *= i;
		if (ans >= div) {
			ans %= div;
		}
	}

	cout << ans;

	return 0;

}

