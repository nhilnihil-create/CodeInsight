#include "bits/stdc++.h"

using namespace std;

int main() {
	int A, B, C;
	cin >> A >> B >> C;
	if (((A+B+C)==17)&&(5 == min(A,min(B,C)))&&(7 == max(A,max(B,C)))) {
		cout << "YES"<<endl;
	}
	else {
		cout << "NO" << endl;
	}
	return 0;
}
