#include<iostream>

using namespace std;

int main() {
	int x, a, b;

	cin >> x >> a >> b;

	int kyoriA = abs(x - a);
	int kyoriB = abs(x - b);

	if (kyoriA > kyoriB) {
		cout << "B" << endl;
	}
	else {
		cout << "A" << endl;
	}

}