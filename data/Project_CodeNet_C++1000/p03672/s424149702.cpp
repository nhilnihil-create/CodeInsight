#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
typedef struct _data {
	int x;
	int y;
} data;

int ev_str(string a)
{
	int len = a.size() / 2;
	if (a.substr(0, len) == a.substr(len, len))
		return a.size();
	else 
		return 0;
}

int  main()
{
	string s;
	cin >> s;
	s.erase(--s.end());
	priority_queue<int> q;
	for (int i = s.size()-1; i >= 0; i--)
	{
		if (i % 2)
		{
			string a = s.substr(0, i+1);
			if (ev_str(a))
			{
				q.push(ev_str(a));
			}
		}
	}
	cout << q.top() << endl;
	return (0);
}
