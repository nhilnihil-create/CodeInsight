#include <bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	cin >> s;

	auto f = [](string t) {
		return ((t.size() % 2 == 0) && (t.substr(0, t.size() / 2) == t.substr(t.size() / 2, t.size())));
	};

	s.pop_back();

	while (!f(s))
	{
		s.pop_back();
	}

	cout << s.size() << endl;

	return 0;
}