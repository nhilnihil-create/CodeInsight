#include "bits/stdc++.h"

using namespace std;

void solve(void)
{
	string s;
	cin >> s;
	int n = s.size();
	if ((s.front() == s.back()) ^ (n&1))
	{
		cout << "First" << endl;
	}
	else
	{
		cout << "Second" << endl;
	}
}

int main()
{
	solve();
	//cout << "yui(*-v・)yui" << endl;
	return 0;
}
