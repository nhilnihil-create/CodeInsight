#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main(void) {

	string s;
	cin >> s;

	s.insert(s.begin() + 4, ' ');

	cout << s << "\n";


	return 0;
}