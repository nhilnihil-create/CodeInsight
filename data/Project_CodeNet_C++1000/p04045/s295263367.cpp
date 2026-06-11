#include<iostream>

using namespace std;

int calc_ketasuu(int n);
bool check(int n);
int kirai[10];
int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 0;i < 10;i++) {
		kirai[i] = 0;
	}
	for (int i = 0;i < k;i++) {
		int t;
		cin >> t;
		kirai[t] = 1;
	}
	while (1) {
		if (check(n))break;
		n++;
	}
	cout << n << endl;

}

int calc_ketasuu(int n) {
	int ans = 0;
	while (n > 0) {
		ans++;
		n /= 10;
	}
	return ans;
}

bool check(int n) {
	while (n > 0) {
		if (kirai[n % 10])return false;
		n /= 10;
	}
	return true;
}