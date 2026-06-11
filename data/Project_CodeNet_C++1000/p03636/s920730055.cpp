#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int		main()
{
	string str,ans;
	int len;
	cin >> str;
	len = str.size();
	cout << str[0] << len - 2 << str[len - 1] << endl;
}