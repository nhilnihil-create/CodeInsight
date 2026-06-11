#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<map>
#include<set>
#include<vector>
#include<functional>
#include <random>
#include<iostream>
#include<iomanip>
using namespace std;

long long a[2000];
long long min_interval[2001][2001];

int N;
long long x;

long long min(long long a, long long b) {
	if (a < b) {
		return a;
	}
	else {
		return b;
	}
}

long long min_int(int i, int j) {
	
	int middle;
	/*[i,j)のminimum*/
	if (min_interval[i][j] != 1000000001) {
		return min_interval[i][j];
	}
	else if (j <= i) {
		return min_interval[i][j];
	}
	else if (j - i == 1) {
		min_interval[i][j] = a[i];
		return min_interval[i][j];
	}
	else {
		middle = (i + j) / 2;
		min_interval[i][j] = min(min_int(i, middle), min_int(middle, j));
		return min_interval[i][j];
	}
}

long long min_int_circ(int i, int k) {
	/*a[i], a[i-1], ..., a[i-k]の最小値*/
	if (i - k >= 0) {
		return min_int(i - k, i + 1);
	}
	else {
		return min(min_int(0, i + 1), min_int(i - k + N, N));
	}
}

int main() {
	cin >> N >> x;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < N+1; i++) {
		for (int j = 0; j < N + 1; j++) {
			min_interval[i][j] = 1000000001;
		}
	}

	long long ans = 1000000000;
	ans *= 100000000;
	for (int i = 0; i < N; i++) {
		long long t = (long long)i * x;
		for (int j = 0; j < N; j++) {
			t += min_int_circ(j, i);
		}
		if (ans > t) { ans = t; }
	}

	cout << ans;
}