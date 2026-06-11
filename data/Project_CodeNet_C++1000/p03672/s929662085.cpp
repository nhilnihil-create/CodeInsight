#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main(void) {
	string S;
	cin >> S;

	int a = S.size();

	for (int i = 0; i < a; i++) {
		S.pop_back();

		if (S.size() % 2 == 0) {
			int A = S.size() / 2;
			string Q = S.substr(0, A);
			string E = S.substr(A, A);
			if (Q == E) {
				cout << S.size() << endl;
				return 0;
			}
		}
	}
}
