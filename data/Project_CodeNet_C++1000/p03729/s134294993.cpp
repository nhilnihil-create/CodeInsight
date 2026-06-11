#include<iostream>

using namespace std;

int main() {
	string A, B, C;
	cin >> A >> B >> C;

	char& Q = A.back();
	char& W = B.front();
	char& E = B.back();
	char& R = C.front();
	if (Q == W && E == R) {
		cout << "YES" << endl;
	}
	else cout << "NO" << endl;

	return 0;
}