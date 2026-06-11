#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> getDigits(int n) {
	vector<int> rD;
	while (n) {
		rD.push_back(n % 10);
		n /= 10;
	}
	reverse(rD.begin(), rD.end());
	return rD;
}

bool isDigitBad(vector<int> v, int n) {
	for (int i: v) {
		if (i == n) return true;
	}
	return false;
}

bool isNumberBad(vector<int> v, int n) {
	vector<int> dis = getDigits(n);
	for (int d: dis) {
		if (isDigitBad(v, d)) return true;
	}
	return false;
}

int main() {
	int n, k, lg;
	cin >> n >> k;
	vector<int> badd(k);
	for (int i = 0; i < k; i++) {
		cin >> badd[i];
	}
	while (isNumberBad(badd, n)) {
		n += 1;
	}
	cout << n << endl;
	return 0;
}