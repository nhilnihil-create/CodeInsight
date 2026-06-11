#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "stack"
#include "set"
#include "functional"
#include "algorithm"
#include "math.h"
#include "utility"
#include "string"
#include "map"
#include "unordered_map"
#include "iomanip"
#include "random"

using namespace std;
const long long int MOD = 1000000007;

long long int power(long long int x, long long int n, long long int M) {
	long long int tmp = 1;

	if (n > 0) {
		tmp = power(x, n / 2, M);
		if (n % 2 == 0) tmp = (tmp*tmp) % M;
		else tmp = (((tmp*tmp) % M)*x) % M;
	}
	return tmp;
}

long long int N, M, K, Q, W, H, L, R;
long long int ans;

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	N = 0;
	bool flag[11] = {};
	for (int i = 10; i >= 1; i--) {
		string a, b;
		cout << "? 1";
		for (int j = 1; j < i; j++)cout << '0';
		cout << endl;
		cin >> a;
		cout << "? 9";
		for (int j = 1; j < i; j++)cout << '9';
		cout << endl;
		cin >> b;
		if (a == b&&a == "Y") {
			flag[i] = true;
		}
	}
	for (int i = 0; i < 10; i++) {
		if (flag[i] && !flag[i + 1])N = i;
		if (!flag[i] && flag[i + 1])N = i + 1;
	}
	if (!N) {
		cout << "! 1000000000" << endl;
		return 0;
	}
	L = 1;
	R = 10;
	for (int i = 1; i < N; i++) {
		L *= 10;
		R *= 10;
	}
	while (R - L > 1) {
		string a;
		long long int mid = (R + L) / 2;
		cout << "? " << mid << "0" << endl;
		cin >> a;
		if (a == "Y") {
			R = mid;
		}
		else {
			L = mid;
		}
	}
	string a;
	cout << "? " << R << "0" << endl;
	cin >> a;
	if (a == "Y") {
		cout << "? " << L << "0" << endl;
		cin >> a;
		if (a == "Y") {
			cout << "! " << L << endl;
			return 0;
		}
		cout << "! " << R << endl;
		return 0;
	}
	cout << "! " << L << endl;
	return 0;
}
