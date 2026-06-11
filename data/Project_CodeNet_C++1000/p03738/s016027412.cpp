#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main() {
	string A, B;
	cin >> A >> B;
	int rec = 0;
	if (A.length() > B.length()) {
		cout << "GREATER" << endl;
	}
	else if (A.length() < B.length()) {
		cout << "LESS" << endl;
	}
	else {
		for (int i = 0 ; i < A.length(); i++) {
			if (A[i] > B[i]) {
				cout << "GREATER" << endl;
				rec++;
				break;
			}
			else if (A[i] < B[i]) {
				cout << "LESS" << endl;
				rec++;
				break;
			}
		}
		if (rec == 0) {
			cout << "EQUAL" << endl;
		}
	}
	return 0;
}