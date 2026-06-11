#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<set>
#include<map>
#include<iomanip>

using namespace std;

int main(void) {
	string s;
	cin >> s;
	if (s[0] == 'Y'&&s[1] == 'A'&&s[2] == 'K'&&s[3] == 'I') {
		cout << "Yes";
	}
	else {
		cout << "No";
	}
	return 0;
}