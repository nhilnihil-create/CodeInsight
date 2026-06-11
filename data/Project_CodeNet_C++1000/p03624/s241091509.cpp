#include<iostream>
#include<string.h>
#include<vector>
using namespace std;
int main() {
	string s;
	char c;
	cin >> s;
	vector<int> alpha(26, 0);
	for (int i = 0; i < s.size(); i++) {
		alpha.at(s.at(i) - 'a') = 1;
	}
	for (int i = 0; i < 26; i++) {
		if (alpha.at(i) == 0) {
			c = 'a' + i;
			cout << c << endl;
			return 0;
		}
	}
	cout << "None" << endl;
	return 0;

}