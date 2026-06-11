#include <iostream>
#include <sstream>
using namespace std;

int main() {
	string s;
	cin >> s;

	stringstream ss;
	ss << s.at(0) << s.length()-2 << s.at(s.length()-1);
	string ans = ss.str();
	cout << ans << endl;
}