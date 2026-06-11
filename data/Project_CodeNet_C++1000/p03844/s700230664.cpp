#include <iostream>
#include <cstdio>
using namespace std;

int a, b;
string op;
int main() {
	cin >> a >> op >> b;
	cout << (op=="+" ? a+b : a-b);
	return 0;
}
