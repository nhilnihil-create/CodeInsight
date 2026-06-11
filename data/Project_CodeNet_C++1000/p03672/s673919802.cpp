#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main() {
	string S;
	cin >> S;

	while (S.length() != 1) {
		S.pop_back();

		if (S.substr(0, S.length() / 2) == S.substr(S.length() / 2)) {
			cout << S.length() << endl;
			return 0;
		}
	}
}
