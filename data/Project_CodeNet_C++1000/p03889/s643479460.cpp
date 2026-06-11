#include <bits/stdc++.h>
using namespace std;

void change(string &s)
{
	for (int i = 0; i < s.size(); ++i)
	{
		if (s[i] == 'b')
		{
			s[i] = 'd';
		}
		else if (s[i] == 'd')
		{
			s[i] = 'b';
		}
		else if (s[i] == 'p')
		{
			s[i] = 'q';
		}
		else if (s[i] == 'q')
		{
			s[i] = 'p';
		}
	}
}

int main()
{
	string s, s1;
	cin >> s;
	s1 = s;
	reverse(s1.begin(), s1.end());
	change(s1);
	if (s == s1)
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;
	}
}