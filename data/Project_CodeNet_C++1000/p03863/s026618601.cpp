#include <iostream>
#include <cstring>

using namespace std;

string s;

int main()
{
	cin >> s;
	if (s[0] == s[s.length() - 1] && s.length() % 2) cout << "Second" << endl;
	else if (s[0] == s[s.length() - 1] || s.length() % 2) cout << "First" << endl;
	else cout << "Second" << endl;
	return 0;
}