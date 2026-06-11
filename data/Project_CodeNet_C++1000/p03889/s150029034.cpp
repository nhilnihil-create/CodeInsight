#include <bits/stdc++.h>
using namespace std;
string s;
int main()
{
	cin >> s;
	string s1 = s;
	reverse(s.begin(),s.end());
	for (int i = 0;i < s.size();i++)
	{
		if (s[i] == 'b')
		    s[i] = 'd';
		else if (s[i] == 'd')
		    s[i] = 'b';
		else if (s[i] == 'p')
		    s[i] = 'q';
		else
		    s[i] = 'p';
	}
	if (s1 == s)
	    cout << "Yes\n";
	else
	    cout << "No\n";
	return 0;
}