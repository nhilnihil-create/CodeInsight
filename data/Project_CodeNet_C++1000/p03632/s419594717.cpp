#include<iostream>
using namespace std;

int main() {
	int A, B, C, D;
	cin >> A >> B >> C >> D;

	int MaxNum = max(A, C);
	int MinNum = min(B, D);

	cout << max(0, MinNum - MaxNum) << endl;
}