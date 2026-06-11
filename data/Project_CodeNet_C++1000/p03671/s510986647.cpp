#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
#include<string.h>
using namespace std;

int main() {
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(0);

	int A, B, C, l = 0, k = 0, o = 0; cin >> A >> B >> C;
	if (A <= B && A <= C) {
		cout << A + min(C, B) << endl;
	}
	else if (B <= A && B <= C) {
		cout << B + min(C, A) << endl;
	}
	else if (C <= A && C <= A) {
		cout << C + min(A, B) << endl;
	}
	else if(A==B&&C==B) cout << A + B << endl;
	return 0;
}

