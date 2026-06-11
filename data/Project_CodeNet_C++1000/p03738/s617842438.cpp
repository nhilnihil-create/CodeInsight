#include<iostream>
#include<iomanip>
#include<vector>
#include<string>
#include<utility>
#include<map>
#include<algorithm>

using namespace std;
using ll = long long;

int main() {
	string A, B;
	cin >> A >> B;

	if (A.size() < B.size()) {
		cout << "LESS" << endl;
		return 0;
	}
	else if (A.size() > B.size()) {
		cout << "GREATER" << endl;
		return 0;
	}
	else {
		for (int i = 0; i < (int)A.size(); i++) {
			char& A_tmp = A[i];
			char& B_tmp = B[i];
			int Q = A_tmp - '0';
			int W = B_tmp - '0';

			if (Q < W) {
				cout << "LESS" << endl;
				return 0;
			}
			else if (Q > W) {
				cout << "GREATER" << endl;
				return 0;
			}
		}

		cout << "EQUAL" << endl;
		return 0;
	}
}