#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
	string s;
	string ret = "";

	cin >> s;

	rep(i, s.length())
	{
		if ( (i + 1) % 2 == 1)
		{
			ret += s.at(i);
		}
	}

	cout << ret << endl;
	return 0;
}