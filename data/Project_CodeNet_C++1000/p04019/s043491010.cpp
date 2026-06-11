#include <bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	cin >> s;
	map<char, int> M;
	for (int i = 0; i < s.size(); ++i)
	{
		M[s[i]] = 1;
	}
	cout << (M['N'] == M['S'] && M['E'] == M['W']?"Yes":"No") << endl;
	return 0;
}