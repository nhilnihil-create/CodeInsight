#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
typedef long long int ll;
#define mod 1000000007


void solve()
{
	string str;
	cin >> str;

	stack<int> s;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '0')
			s.push(0);
		else if (str[i] == '1' )
			s.push(1);
		else
		{
			if (s.empty() == false)
				s.pop();
		}
	}

	stack<int> temp;
	while (s.empty() == false)
	{
		temp.push(s.top());
		s.pop();
	}

	while (temp.empty() == false)
	{
		cout << temp.top() ;
		temp.pop();
	}


}



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("1input.txt", "r", stdin);
	freopen("1output.txt", "w", stdout);
#endif

	int t = 1;
	// cin >> t;

	while (t--)
	{
		solve();
		cout << "\n";
	}

	return 0;
}