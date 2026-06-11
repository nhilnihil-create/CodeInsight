#include<iostream>
using namespace std;

int main() {
	string A, B, C;
	cin >> A >> B >> C;

	char& a = A[0];
	char& b = B[0];
	char& c = C[0];

	cout << char(a - 32) << char(b - 32) << char(c - 32) << endl;
}