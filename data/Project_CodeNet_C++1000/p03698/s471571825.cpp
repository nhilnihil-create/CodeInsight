#include <bits/stdc++.h>
using namespace std;
 
int main()
{
	string s;
	cin >> s;
	map<char, bool> M;
	for (auto o : s)
	{
		if(M[o])
		{
			cout << "no" << endl;
			return 0;
		}
		M[o] = 1;
	}
	cout << "yes" << endl;
	return 0;
}