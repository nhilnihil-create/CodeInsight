#include <iostream>
#include <cmath>
#include <climits>
#include <string>
#include <numeric>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <functional>
#include <iomanip>

using namespace std;
using ll = long long;

template<typename T> void print(T t) { cout << t << endl; }

bool check(int a, int s, int c) {
	for (int ss = 1; ss < s; ss++) a /= 10;
	return a % 10 == c;
}
int main() {
	ll N, A, B;
	cin >> N >> A >> B;

	if (N == 1) {
		if (A == B) {
			print(1);
		}
		else {
			print(0);
		}
	}
	else {
		if (A > B) {
			print(0);
		}
		else {
			ll maxSum = A + (N - 1) * B;
			ll minSum = B + (N - 1) * A;
			print(maxSum - minSum + 1);
		}
	}
}

