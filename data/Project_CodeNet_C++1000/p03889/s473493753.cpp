#include<bits/stdc++.h>
using namespace std;
string s, s1;

int main()
{
	getline(cin, s);
	s1 = s;
	reverse(s1.begin(), s1.end());
	for (int i = 0; i < s1.size(); i++)
	{
		if (s1.at(i) == 'b') s1.at(i) = 'd';
		else if (s1.at(i) == 'd') s1.at(i) = 'b';
		else if (s1.at(i) == 'p') s1.at(i) = 'q';
		else if (s1.at(i) == 'q') s1.at(i) = 'p';
	}
	if (s1 == s) puts("Yes"); else puts("No");
	return 0;
}
