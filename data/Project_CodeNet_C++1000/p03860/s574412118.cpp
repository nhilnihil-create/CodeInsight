#include <iostream>
#include <string>
using namespace std;

int main() {
	for (int i = 0; i < 3; i++) {
		string a;
		cin >> a;
		cout << a.at(0);
	}
}