#include<iostream>
using namespace std;
int a[5];
int main()
{
	int n; cin >> n;
	string s; cin >> s; int c = 0,mx=0;
	for (int i = 0; i < s.size(); ++i)
	{
		if (s[i] == 'I')
			c++;
		else if (s[i] == 'D')
			c--;
		mx= max(c, mx);

	}
	cout << mx;
}
