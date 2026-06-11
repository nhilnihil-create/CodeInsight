#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pint = pair<int, int>;

int main() {
	string A, B;
	cin >> A >> B;

	if (A == B) {
		cout << "EQUAL" << endl;
		return 0;
	}

	if (A.size() > B.size()) {
		cout << "GREATER" << endl;
	}
	else if (A.size() < B.size()){
		cout << "LESS" << endl;
	}
	else {
		for (int i = 0; i < A.size(); ++i) {
			if (A[i] > B[i]) {
				cout << "GREATER" << endl;
				break;
			}
			else if (A[i] < B[i]) {
				cout << "LESS" << endl;
				break;
			}
		}
	}
	return 0;
}
