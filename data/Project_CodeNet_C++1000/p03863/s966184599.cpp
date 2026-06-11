#include<iostream>
#include<string>
using namespace std;
string s;
int main() {
	cin >> s;
	unsigned len=s.size();
	bool(s[0]==s[len-1])?(bool(len%2)?cout << "Second\n":cout << "First\n"):(bool(len%2)?cout << "First\n":cout << "Second\n");
	return 0;
}