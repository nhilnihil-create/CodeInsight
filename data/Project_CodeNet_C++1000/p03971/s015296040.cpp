#include <bits/stdc++.h>
using namespace std;
 
int main()
{
	int n, A, B;
	cin >> n >> A >> B;
	string s;
	cin >> s;
	s = ' ' + s;
	int nowa = 0, nowb = 0;
	for (int i = 1; i < s.size(); ++i)
	{
		if (s[i] == 'a')
		{
			if(nowa + nowb < A + B)
			{
				cout << "Yes" << endl;
				nowa++;
			}
			else
			{
				cout << "No" << endl;
			}
		}
		else if(s[i] == 'b')
		{
			if(nowa + nowb < A + B && nowb < B)
			{
				cout << "Yes" << endl;
				nowb++;
			}
			else
			{
				cout << "No" << endl;
			}
		}
		else
		{
			cout << "No" << endl;
		}
	}
	return 0;
}