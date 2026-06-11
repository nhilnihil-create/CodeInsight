#include <bits/stdc++.h>
using namespace std;

int main()
{
	int h, w;
	cin >> h >> w;
	vector<string> ss(h);
	for (auto &&s : ss)
	{
		cin >> s;
	}

	cout << string(w + 2, '#') << endl;
	for (auto &&s : ss)
	{
		cout << '#' << s << '#' << endl;
	}
	cout << string(w + 2, '#') << endl;

	return 0;
}