#include <iostream>
#include <cstdio>
using namespace std;

int x, a, b;
int main() {
	cin >> x >> a >> b;
	b -= a;
	cout<<(b<=0 ? "delicious" : b<=x ? "safe" : "dangerous");
	return 0;
}