#if 1
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <climits>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <functional>
#include <set>
#include <numeric>
#include <cassert>

using namespace std;
#define int long long
#define uint unsigned long long
constexpr int MOD = 1000000007;
constexpr int INF = 1145141919810;

#define LOADVEC(type,name,N) std::vector<type>name(N); \
for (int nnn = 0; nnn < N; ++nnn) { \
	cin >> name[nnn]; \
}

#define LOADVEC2(type,name0,name1,N) std::vector<type>name0(N),name1(N); \
for (int nnn = 0; nnn < N; ++nnn) { \
	cin >> name0[nnn];cin >> name1[nnn]; \
}

#define LOAD(type,name) type name; \
cin >> name;


void proc();

signed main() {
	ios::sync_with_stdio(false);
	proc();
	return 0;
}

/*
--------------------------------------------------------
--------------------------------------------------------
---------------    template      ----------------------
--------------------------------------------------------
--------------------------------------------------------
*/

bool proc2() {
	LOAD(int, N);
	LOADVEC(int, A, N);
	if (N == 1) {
		return true;
	}
	std::vector<int>B(N);
	int sum = A[0];
	for (int i = 1; i < N; ++i) {
		B[i] = A[i] - A[i - 1];
		sum += A[i];
	}
	B[0] = A[0] - A[N - 1];
	int M = N * (N + 1) / 2;
	if (sum%M != 0) {
		return false;
	}
	int k = sum / M;
	for (int i = 0; i < N; ++i) {
		int tmp = k - B[i];
		if (tmp % N != 0 || tmp < 0) {
			return false;
		}
	}
	return true;
}

void proc() {
	if (proc2()) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}
}


#endif
