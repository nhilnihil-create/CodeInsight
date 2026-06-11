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
	int N;
	cin >> N;
	vector<int> vec(N);
	for (int i = 0; i < N; ++i) {
		cin >> vec[i];
	}

	int minCost = INT_MAX;
	for (int i = -100; i < 101; ++i) {
		int cost = 0;
		for (size_t t = 0; t < vec.size(); ++t) {
			cost += pow(vec[t] - i, 2);
		}

		minCost = min(cost, minCost);
	}

	cout << minCost << endl;
	return 0;
}