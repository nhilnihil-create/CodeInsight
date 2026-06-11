#include <bits/stdc++.h>
#define re runtime_error
using namespace std;

int cal(int a, char op, int b) {
	switch (op) {
		case '+': return a + b;
		case '-': return a - b;
		case '*': return a * b;
		case '/': {
			if (b == 0) throw re("You can't divide by 0");
			else return a / b;
		}
		default: throw re("No such operator");
	}
}

int main() {
	int a, b; char op;
	cin >> a >> op >> b;
	cout << cal(a, op, b) << '\n';
}
