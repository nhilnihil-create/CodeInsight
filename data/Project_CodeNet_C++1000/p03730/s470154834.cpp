#include <algorithm>
#include <cmath>
#include <climits>
#include <functional>
#include <iostream>
#include <queue>
#include <string>
#include <numeric>
#include <vector>

using namespace std;
using ll = long long;
template<typename T> void print(T t) {cout << t << endl;}
;
int main() {
	int A, B, C;
	cin >> A >> B >> C;
	for (int i = 1; i <= B; i++) {
		if ((A * i) % B == C) {
			print("YES");
			return 0;
		}
	}
	print("NO");
	return 0;
}