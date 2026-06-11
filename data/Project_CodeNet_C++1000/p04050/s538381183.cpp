#include <iostream>
#include <vector>
#include <cassert>
using namespace std;
int n, m, a[100009]; vector<int>A, B, C, D;
int main() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> a[i];
		if (a[i] % 2 == 0)A.push_back(a[i]);
		if (a[i] % 2 == 1)B.push_back(a[i]);
	}
	if (B.size() >= 3) { cout << "Impossible" << endl; return 0; }
	if (m == 1) {
		if (n == 1)cout << "1" << endl << "1" << endl << "1" << endl;
		else {
			cout << n << endl;
			cout << "2" << endl;
			cout << n - 1 << " " << 1 << endl;
		}
	}
	else {
		if (B.size() >= 1)C.push_back(B[0]);
		for (int i = 0; i < A.size(); i++)C.push_back(A[i]);
		if (B.size() >= 2)C.push_back(B[1]);
		if (C[0] >= 2)D.push_back(C[0] - 1);
		for (int i = 1; i < (int)C.size() - 1; i++)D.push_back(C[i]);
		D.push_back(C[C.size() - 1] + 1);

		for (int i = 0; i < C.size(); i++) { if (i)cout << " "; cout << C[i]; }cout << endl;
		cout << D.size() << endl;
		for (int i = 0; i < D.size(); i++) { if (i)cout << " "; cout << D[i]; }cout << endl;
	}
	return 0;
}