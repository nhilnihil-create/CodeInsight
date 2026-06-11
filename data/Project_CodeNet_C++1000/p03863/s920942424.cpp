#include <bits/stdc++.h>
using namespace std;

int main()
{
	string str;
	cin >> str;
	int num = str.size()-3;
	if (str[0] != str[str.size()-1]) num++;
	if (num%2 == 0) cout << "Second" << endl;
	else cout << "First" << endl;
	return 0;
}