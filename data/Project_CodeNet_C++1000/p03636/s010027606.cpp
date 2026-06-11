#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	string s;
	cin >> s;
	int l;
	l = s.size();
	int sum = l - 2;
	cout << s[0] << sum << s[l - 1] << endl;
	return 0;
}