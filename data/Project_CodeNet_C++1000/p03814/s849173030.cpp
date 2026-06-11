#include<bits/stdc++.h>
using namespace std;


int main()
{
	string s; cin >> s;
	int b, e;
	for (int i = 0; i < s.size()/2; ++i)
		if (s[i] == 'A')
		{
			 b = i;
			 break;
		}
	for (int i = s.size()-1; i >= 0; --i)
		if (s[i] == 'Z')
		{
			e = i;
			break;
		}
	cout << e-b+1 << endl;
}


