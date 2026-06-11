#include <iostream>
#include <string>
using namespace std;

int main() {
	string S;
	cin >> S;
	for (int i = 0; i < 12; i++) {
		if (i == 3) cout << S.at(i) << ' ';
		else cout << S.at(i);
	}
	cout << endl;
}