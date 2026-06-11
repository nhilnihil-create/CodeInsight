#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <string>
#include <cmath>
using namespace std;

#undef INT_MIN
#undef INT_MAX
#define INT_MIN -2147483648
#define INT_MAX 2147483647

int main() {
	long long N, M;
	cin >> N >> M;
	long long count = 0;
	if (N * 2 <= M) {
		count += N;
		M -= 2 * N;
		N = 0;
		count += M / 4;
	}
	else if(M < 2 * N){
		count += M / 2;
	}

	cout << count << endl;
	return 0;
}