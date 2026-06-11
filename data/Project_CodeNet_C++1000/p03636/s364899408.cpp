
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s, ans;
	cin >> s;

	ans = s.substr(1, s.size() - 1);

	cout << s.substr(0, 1) << ans.size() - 1 << s.substr(s.size() - 1, 1) << endl;
}

