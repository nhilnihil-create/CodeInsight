#include <bits/stdc++.h>

using namespace std;

int main() {

	string A, B, C;
	cin >> A >> B >> C;

	if((A[(int)A.length() - 1] == B[0]) && (B[(int)B.length() - 1] == C[0])) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}

	return 0;
}