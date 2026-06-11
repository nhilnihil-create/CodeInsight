#include<iostream>
#include<stdio.h>
#include<cstring>
using namespace std;
int main()
{
	string s;
	cin >> s;
	int len = s.size();
	//cout << s << "￥" << s.size() << endl;
	for (int i = 0; i < len - 1; i++)
	{
		//cout << s[i] << "@" << endl;
		if (s[i] == 'S' && s[i + 1] == 'T')
		{
			//cout << i << "%" << i + 1 << endl;
			s.erase(i, 2);
			len -= 2;
			i -= 2;
		}
	}
	cout << len<< endl;

	return 0;
}