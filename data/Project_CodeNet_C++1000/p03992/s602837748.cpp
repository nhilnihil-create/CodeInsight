#include<iostream>
#include<string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string S;
	cin >> S;
	cout << S.substr(0, 4) << " " << S.substr(4, S.back());
	cout << endl;
	return 0;
}