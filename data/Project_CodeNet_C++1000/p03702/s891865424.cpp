#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<algorithm>
#include<stdio.h>

using namespace std;

long long m[100010], n, a, b;

int check(long long  times) {
	long long an = 0;
	long long p = times * b;
	long long q = a - b;
	for (int i = n - 1; i >= 0; i--) {
		if (m[i] > p) {
			an += (m[i] - p) / q + ((m[i] - p) % q == 0 ? 0 : 1);
		}
	}
	if (an > times) {
		return 0;
	}
	else {
		return 1;
	}
}

/*int find(long long  left, long long right) {
	//cout << left <<" "<< right << endl;
	if (left >= right) {
		return left;
	}
	int mid = (left + right) >> 1;
	if (check(mid)) {
		find(left, mid);
	}
	else {
		find(mid + 1, right);
	}
}*/

int main() {
	scanf("%lld%lld%lld", &n, &a, &b);
	long long shp = 0;
	for (int i = 0; i < n; i++) {
		scanf("%lld", &m[i]);
		shp += m[i] / b + 1;
	}
	sort(m, m + n);
	long long left = 1, right = shp;
	while (left < right) {
		long long mid = (left + right) >> 1;
		if (check(mid)) {
			right = mid;
		}
		else{
			left = mid + 1;
		}
	}
	cout << left << endl;
}