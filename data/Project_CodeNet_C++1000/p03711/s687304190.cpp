#include "bits/stdc++.h"
using namespace std;

int main() {
	int data[] = {0,1,0,2,0,2,0,0,2,0,2,0};
	int A, B;
	cin >> A >> B;
	A--;
	B--;
	if (data[A] ==data[B]) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
	return 0;
}