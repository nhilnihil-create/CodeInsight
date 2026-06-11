#include <iostream>
#include <string>
#include <sstream>

using namespace std;


int main() {
	string str;
	cin >> str;

	int length;
	ostringstream strlen;
	length = str.size() - 2;
	strlen << length;

	str.replace(1, length, strlen.str());
	cout << str << endl;

	return 0;
}