#include <iostream>
using namespace std;

int main() {
	int X;
	cin >> X;
	int hik = 0;
	int add = 1;
	while (hik < X) {
		hik += add;
		add++;
	}
	cout << add - 1<< endl;
}