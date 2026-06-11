#include <cstdio>
#include <iostream>
#include <stack>
#include <string>
using namespace std;
//yazhan
int main()
{
	stack<char> q;
	string s;
	cin >> s;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == 'S')
		{
			q.push(s[i]);
		}
		else
		{
			if (!q.empty() && q.top() != 'T')
			{
				q.pop();
			}
			else
			{
				q.push(s[i]);
			}
		}
	}
	printf("%d", q.size());


	return 0;
}
