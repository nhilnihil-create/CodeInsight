#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s;
	cin >> s;
	string ans = s.substr(0, 4) + " " + s.substr(4);
	cout << ans << endl;
}
