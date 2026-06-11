#include <iostream>
#include <cstdio>
using namespace std;

int a, b;
int main() {
	cin >> a >> b;
	cout << ((a+b)%3 && a%3 && b%3 ? "Impossible" : "Possible");
	return 0;
}
