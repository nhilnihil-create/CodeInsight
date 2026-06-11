#include "bits/stdc++.h"
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)


int main() {
	vector<int> four,two,other;
	int N, a;
	cin >> N;
	rep(i, N) {
		cin >> a;
		if (a % 4 == 0) {
			four.push_back(a);
		}
		else if (a % 2 == 0) {
			two.push_back(a);
		}
		else {
			other.push_back(a);
		}
	}
	if (N / 2 <= four.size()) {
		cout << "Yes" << endl;
	}
	else if (other.size() <= four.size() ) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
}
