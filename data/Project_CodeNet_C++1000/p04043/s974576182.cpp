#include<iostream>
using namespace std;
int main() {

	int A[3];
	cin >> A[0] >> A[1] >> A[2];

	int cnt5=0, cnt7=0;
	for (int i = 0; i < 3; i++) {
		if (A[i] == 5) cnt5++;
		else if (A[i] == 7) cnt7++;
	}

	if (cnt5 == 2 && cnt7 == 1) cout << "YES" << endl;
	else cout << "NO" << endl;

	return 0;
}