#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
	string S, M;
	cin >> S >> M;
	for (int i = 0; i < S.size(); i++) {
		if (i == 0) {
			cout << S[i];
		}
		else if (i == 1) {
			cout << M[0];
		}
	}
	cout << "C" << endl;
}