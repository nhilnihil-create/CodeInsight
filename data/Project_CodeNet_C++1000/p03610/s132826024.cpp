#include<iostream>

using namespace std;

int main() {
	string S;
	cin >> S;

	for (int i = 0; i < S.length(); i++) {
		if (i % 2 == 0) {
			cout << S[i];
		}
	}

	cout << endl;


}