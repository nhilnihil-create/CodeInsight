#include <bits/stdc++.h>
#define rep(i, n) for(long long i = 0; i < (n); i++)
using namespace std;

signed main(void)
{
	string s;
	stack<char> st;
	int n;

	cin >> s;
	n = s.size();
	rep(i, n)
	{
		if (st.size() == 0)
			st.push(s[i]);
		else if (s[i] == 'T')
		{
			if (st.top() == 'S')
				st.pop();
			else
				st.push(s[i]);
		}
		else if (s[i] == 'S')
		{
			st.push(s[i]);
		}
	}
	cout << st.size() << endl;
	return 0;
}
