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

using namespace std;
using ll = long long;

int main() {
	int N;
	cin >> N;
	int K;
	cin >> K;
	int A = 0;
	int B = 0;
	int total =0;

	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		
		A = x * 2;
		B = (K - x)*2;

		total += min(A,B);

	}
	cout << total << endl;
}
