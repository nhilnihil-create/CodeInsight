#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;
int main() {
	int a, b = 0, c = 1, e;
	cin >> a;
	while (a > b) {
		b = 0;
		for (int h = 1; h <= c; h++) {
			b += h;
		}
		c++;
	}
	cout << c - 1 << endl;
	cin >> e;
}