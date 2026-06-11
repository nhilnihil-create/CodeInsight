#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 0; i <= (int)(n); i++)
using P = pair<int,int>;
using pq = priority_queue<int>;
typedef long long ll;

int  main()
{
	string s; cin >> s;

	rep(i, s.size())
	{
		if (i%2 == 0)
			cout << s[i];
	}
	cout << endl;
	return 0;
}