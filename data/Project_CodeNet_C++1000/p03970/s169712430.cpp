#include <iostream>
using namespace std;

int main() {
	string R = "CODEFESTIVAL2016";
	string S;
	cin >> S;
	int ans = 0;
	for (int i = 0; i < R.length(); i++) ans += (S[i] != R[i]);
	cout << ans << endl;
}