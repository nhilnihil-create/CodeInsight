#include <iostream>
#include <algorithm>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <list>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <bitset>
#include <random>
#include <complex>
#include <assert.h>

using namespace std;
typedef long long ll;
#define endl '\n'

template<typename T>
inline bool chmin(T& x, T a) {
	if (x >= a) { x = a; return true; }
	return false;
}

template<typename T>
inline bool chmax(T& x, T a) {
	if (x <= a) { x = a; return true; }
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(0);

	int N, M; cin >> N >> M;
	vector<int> v(N);
	for (int i = 0; i < M; i++) {
		int a, b; cin >> a >> b;
		v[a - 1]++;
		v[b - 1]++;
	}

	bool f = true;
	for (int i = 0; i < N; i++) {
		if (v[i] % 2 == 1) { f = false; }
	}

	if (f) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}

	return 0;
}