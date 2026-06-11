#include<iostream>
#include<cmath>
using namespace std;
int main() {
	long long int A, B, C;
	cin >> A >> B >> C;
	long long int sum = A + B + C;
	long long int count = 0;
	while (1) {
		if (A % 2 == 1 || B % 2 == 1 || C % 2 == 1) {
			break;
		}
		A = (sum - A)/2;
		B = (sum - B)/2;
		C = (sum - C)/2;
		count++;
		if (A == B && B == C) {
			count = -1;
			break;
		}
		if (A % 2 == 1 || B % 2 == 1 || C % 2 == 1) {
			break;
		}
	}
	cout << count << endl;
	return 0;
}