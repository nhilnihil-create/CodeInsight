#include <bits/stdc++.h>
using namespace std;
 
int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	map<tuple<int, int, int>, int> m;
	int count = 0, na = a, nb = b, nc = c;
	int ta, tb, tc;
	while(1)
	{
		if(m[make_tuple(na, nb, nc)])
		{
			cout << -1 << endl;
			break;
		}
		if(na % 2 == 1 || nb % 2 == 1 || nc % 2 == 1)
		{
			cout << count << endl;
			return 0;
		}
		m[make_tuple(na, nb, nc)] = 1;
		int ta = na;
		int tb = nb;
		int tc = nc;
		ta = nc / 2 + nb / 2;
		tb = na / 2 + nc / 2;
		tc = na / 2 + nb / 2;
		na = ta;
		nb = tb;
		nc = tc;
		++count;
	}
	return 0;
}