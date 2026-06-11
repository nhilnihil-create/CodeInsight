#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
#include <iomanip>


using namespace std;



int main() {

	string A, B;

	cin >> A >> B;

	if (A.size() > B.size()) {
		cout << "GREATER";
	}
	else if (A.size() < B.size()) {
		cout << "LESS";
	}
	else {
		for (int i = 0; i < A.size(); i++) {
			if (A[i] > B[i]) {
				cout << "GREATER";
				goto End;
			}
			else if (A[i] < B[i]) {
				cout << "LESS";
				goto End;
			}
		}
		cout << "EQUAL";

	}
	
	End:
	return 0;

}