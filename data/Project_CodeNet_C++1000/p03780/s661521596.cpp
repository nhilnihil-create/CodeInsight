#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string>
#include<cmath>
#include<vector>
#include<functional>
#include<stack>
#include<utility>
#include<map>
#include<queue>

using namespace std;

long long n, k, a[5000], d = 0;

long long solve(long long t, long long s) {
	if (t == n)
		return 0;
	if (a[t] >= s) {
		d = t+1;
		return solve(t + 1, s);
	}
	else return solve(t + 1, s - a[t]);
}

int main() {
	cin >> n >> k;
	for (long long i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n, greater<int>());
	solve(0, k);
	cout << n - d << endl;
	return 0;
}