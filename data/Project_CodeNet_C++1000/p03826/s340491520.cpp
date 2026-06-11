#include<iostream>

using namespace std;

int main() {
	int A, B, C, D;

	//入力
	cin >> A >> B >> C >> D;

	//面積を求める
	int S1 = A * B;
	int S2 = C * D;

	if (S1 > S2) {
		cout << S1 << endl;
	}
	else if (S1 < S2) {
		cout << S2 << endl;
	}
	else {
		cout << S1 << endl;
	}

}