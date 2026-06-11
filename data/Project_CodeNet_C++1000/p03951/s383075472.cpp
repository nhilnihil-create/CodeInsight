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

int main() {
	int N, c;
	string s, t;
	cin >> N >> s >> t;

	for (c = N; c > 0; c--) {
		bool ok = true;
		for (int i = 0; i < c; i++) {
			if (s[N - c + i] != t[i]) {
				ok = false;
				break;
			}
		}
		if (ok)break;
	}

	print(2 * N - c);
}