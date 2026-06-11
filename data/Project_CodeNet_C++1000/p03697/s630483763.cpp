#include<iostream>
using namespace std;

int main(void) {
	int A, B;
	cin >> A >> B;
	int Ans = A + B;
	if (Ans >= 10) {
		cout << "error" << endl;
	}
	else {
		cout << Ans << endl;
	}
}