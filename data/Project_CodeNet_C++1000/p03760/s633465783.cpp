#include <bits/stdc++.h>
using namespace std;

int main()
{
	string o, e;
	cin >> o >> e;
	for (int i = 0; i < o.size() + e.size(); ++i)
	{
		cout << (i%2==0?o[i/2]:e[i/2]);
	}
	cout << endl;
	return 0;
}