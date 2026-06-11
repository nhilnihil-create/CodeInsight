#include<cstdio>
#include<iostream>
#include<string>

using namespace std;

int main(void) {

	int k, num = 0;

	string s;

	cin >> s;

	if (equal(s.begin(), s.begin() + 4, "YAKI"))cout << "Yes\n";
	else cout << "No\n";

	return 0;
}