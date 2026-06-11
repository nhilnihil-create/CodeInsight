#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	cin >> N;
	int A_max = 0;
	int last_B = 0;
	for (int i = 0; i < N; i++) {
		int a, b = 0;
		cin >> a >> b;
		if (a > A_max) {
			A_max = a;
			last_B = b;
		}
	}
	cout << A_max + last_B << endl;
}