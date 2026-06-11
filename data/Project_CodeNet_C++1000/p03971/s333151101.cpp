/*https://atcoder.jp/contests/code-festival-2016-qualb/tasks/codefestival_2016_qualB_b*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	int n, a, b;
	string s;
	cin >> n >> a >> b;
	cin >> s;
	int pass = 0, orank = 0;
	for (int i = 0; i < n; i++)
	{
		if (pass < a + b)
		{
			if (s[i] == 'a')
				pass++, cout << "Yes" << endl;
			else if (s[i] == 'b')
			{
				orank++;
				if (orank <= b)
					pass++, cout << "Yes" << endl;
				else
					cout << "No" << endl;
			}
			else
				cout << "No" << endl;
		}
		else
			cout << "No" << endl;
	}
}