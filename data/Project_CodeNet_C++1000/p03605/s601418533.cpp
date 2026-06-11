// ABC073A - 

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long int ull;
typedef long long int ll;

int main() {
	int N;
	cin >> N;

	bool ans = false;

	while (N > 0) {
		if (N % 10 == 9) {
			cout << "Yes" << endl;
			return 0;
		}
		N /= 10;
	}

	cout << "No" << endl;

	return 0;
}
