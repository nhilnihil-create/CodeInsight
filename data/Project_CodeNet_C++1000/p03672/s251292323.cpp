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

int main() {
	string S; cin >> S;
	int N = (int)S.length();
	for (size_t n = N/2-1; n >=0; n--) {
		bool ok = true;
		for (int j = 0; j < n; j++) {
			if (S[j] != S[j + n]) ok = false;
		}
		if (ok) {
			print(n * 2);
			return 0;
		}
	}
	return 0;
}