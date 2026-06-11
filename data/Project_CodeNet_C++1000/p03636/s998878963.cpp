#include<iostream>
#include<string>

using namespace std;


int main() {
	string str;
	int str_length;
	cin >> str;
	str_length = str.length();
	str.replace(1, str_length - 2, to_string(str_length - 2));
	cout << str << endl;

	return 0;
}
