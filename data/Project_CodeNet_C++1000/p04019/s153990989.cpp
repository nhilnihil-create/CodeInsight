#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string	str;
	cin >> str;
	bool	n;
	bool	s;
	bool	w;
	bool	e;
	n = false;
	s = false;
	w = false;
	e = false;
	rep(i, str.size())
	{
		if (str.at(i) == 'N') n = true;
		if (str.at(i) == 'S') s = true;
		if (str.at(i) == 'W') w = true;
		if (str.at(i) == 'E') e = true;
	}
	if (n == s && w == e)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
}
