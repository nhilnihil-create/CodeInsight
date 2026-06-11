#include "bits/stdc++.h"
using namespace std;


int main() {

	int N;
	cin >> N;
	vector<int64_t> A(N);
	for (int i = 0;i < N;i++) {
		cin >> A.at(i);
	}

	int count_odd = 0;
	for (int i = 0;i < N;i++) {
		if (A.at(i) % 2 != 0) {
			count_odd++;
		}
	}
	if (count_odd % 2 == 0) {
		cout << "YES";
	}

	else
		cout << "NO";
}
