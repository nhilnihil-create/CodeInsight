#include <iostream>
#include <string>

using namespace std;


int main() {
	string str;
	cin >> str;

	string odd_string = "";
	for (int i = 0; i < str.size(); i++) {
		if (i % 2 == 0) {
			odd_string.push_back(str[i]);
		}
	}

	cout << odd_string << endl;

	return 0;
}