#include <bits/stdc++.h>
using namespace std;
int main()
{
	string w;
	cin >> w;
	map<char, int> counter;

	for (int i = 0; i < w.size(); i++)
	{
		counter[w[i]]++;
	}

	bool ans = true;
	for (int i = 0; i < w.size(); i++)
	{
		if (counter[w[i]] % 2 != 0)
			ans = false;
	}
	if (ans)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
}