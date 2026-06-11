#include <bits/stdc++.h>
using namespace std;

string s;
int len;
int main()
{
	ios :: sync_with_stdio(false);
	cin >> s;
	len = s.size();
	if(len & 1) 
	{
		cout << "No";
		return 0;
	}
	for (register int i = 0;i < len;i ++)
	{
		if(s[i] == 'p' && s[len - i - 1] != 'q'){
			cout << "No";
			return 0;
		}
		if(s[i] == 'q' && s[len - i - 1] != 'p'){
			cout << "No";
			return 0;
		}
		if(s[i] == 'd' && s[len - i - 1] != 'b'){
			cout << "No";
			return 0;
		}
		if(s[i] == 'b' && s[len - i - 1] != 'd'){
			cout << "No";
			return 0;
		}
	}
	cout << "Yes";
} 