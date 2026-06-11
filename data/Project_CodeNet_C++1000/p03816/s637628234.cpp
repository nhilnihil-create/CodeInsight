#include <bits/stdc++.h>
#define PI 3.14159265359
using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int> v(100000);
	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		v.at(n - 1) = 1;
	}

	int n = count(v.begin(), v.end(), 1);
	if (n % 2 == 0) {
		n--;
	}

	cout << n << endl;
}