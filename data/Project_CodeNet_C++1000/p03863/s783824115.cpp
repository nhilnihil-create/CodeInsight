#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 1e5 + 50;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin >> s;
	int n = s.length();
	if(s[0] == s[n-1])
	{
		if(n % 2)
		{
			cout << "Second" << endl;
		}
		else
		{
			cout << "First" << endl;
		}
	}
	else
	{
		if(n % 2)
		{
			cout << "First" << endl;
		}
		else
		{
			cout << "Second" << endl;
		}
	}
	return 0;
}