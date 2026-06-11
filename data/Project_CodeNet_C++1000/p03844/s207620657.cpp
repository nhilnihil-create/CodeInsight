#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	int A, B, D;
	string op;
	cin >> A >> op >> B;
	if (op == "+") {
		D = A + B;
	}
	else if (op == "-") {
		D = A - B;
	}else if (op == "*") {
		D = A * B;
	}else if (op == "/") {
		D = A / B;
	}
	cout << D << endl;
}