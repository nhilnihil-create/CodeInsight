#include <bits/stdc++.h>

using namespace std;

bool check[200001];

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	memset(check,true,sizeof(check));
	string s;

	cin >> s;

	stack <int> stk;

	for(int i=0;i<s.length();i++)
	{
		if(s[i]=='S')
		{
			stk.push(i);
		}
		else
		{
			if(!stk.empty())
			{
				check[stk.top()] = false;
				stk.pop();
				check[i] = false;
			}
		}
	}

	int res = s.length();
	for(int i=0;i<s.length();i++)
	{
		if(check[i]==false)
		{
			res-=1;
		}
	}

	cout << res << '\n';
	
	return 0;
}