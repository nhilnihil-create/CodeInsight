#include<iostream>
#include<string>
using namespace std;

int main() {
	string S;
	cin >> S;

	int A = S.size() - 2;

	cout << S[0] << A << S[S.size() - 1] << endl;
}