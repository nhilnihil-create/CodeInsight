#include<iostream>
#include<string>
using namespace std;

int main() {
	string S;
	cin >> S;

	for (int i = 0; i < S.size(); i++) {
		if (i % 2 == 0) cout << S[i];
	}
}