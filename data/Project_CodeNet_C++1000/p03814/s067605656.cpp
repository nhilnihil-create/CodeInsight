#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int main() {
	string s;
	cin >> s;
	int rec = 0;
	int Rec = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'A') {
			rec = i;
			break;
		}
	}
	for (int i = s.length() - 1; i >= 0; i--) {
		if (s[i] == 'Z') {
			Rec = i;
			break;
		}
	}
	cout << Rec - rec + 1 << endl;
	return 0;
}