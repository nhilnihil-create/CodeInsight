#include <iostream>
using namespace std;

int main() {
	string S; cin >> S;
	for (long long i = 0; i < 4; i++) {
		cout << S.at(i);
	}
	cout << ' ';
	for (long long i = 4; i < 12; i++) {
		cout << S.at(i);
	}
	cout << endl;
}