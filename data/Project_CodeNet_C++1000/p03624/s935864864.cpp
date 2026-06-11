/*https://atcoder.jp/contests/abc071/tasks/abc071_b*/
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
	string s, alpha = "abcdefghijklmnopqrstuvwxyz";
	cin >> s;
	sort(s.begin(), s.end());
	for (int i = 0; i < 26; i++)
	{
		int flag = 0;
		for (int j = 0; j < s.size(); j++)
			if (s[j] == alpha[i]) flag = 1;
		if (flag == 0)
		{
			cout << alpha[i];
			return 0;
		}
	}
	cout << "None";

}