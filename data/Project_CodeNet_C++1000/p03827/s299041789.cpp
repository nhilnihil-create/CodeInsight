#include <bits/stdc++.h>
#define PI 3.14159265359
using namespace std;

int main() {
	int N;
	string S;
	cin >> N >> S;

	int max, x;
	max = 0;
	x = 0;
	for (int i = 0; i < N; i++) {
		char ch = S.at(i);
		if (ch == 'I') {
			x++;
		}
		else if (ch == 'D') {
			x--;
		}

		if (x > max) max = x;
	}

	cout << max << endl;
}