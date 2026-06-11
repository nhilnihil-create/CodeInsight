#include <iostream>
#include <string>

using namespace std;

void solve()
{
	string s;
	cin >> s;
	for (int i = 0; i < 4; ++i)
	{
		cout << s[i];
	}
	cout << " ";
	for (int i = 4; i < s.size(); ++i)
	{
		cout << s[i];
	}
	cout << endl;
}

int main()
{
	solve();
	return(0);
}