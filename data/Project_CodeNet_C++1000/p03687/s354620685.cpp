#include <bits/stdc++.h>

using namespace std;

vector <int> idx[26];
int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	string s;
	int res = 1e9;

	cin >> s;

	for(int i=0;i<s.length();i++)
	{
		idx[s[i]-'a'].push_back(i);
	}
	
	for(int i=0;i<26;i++)
	{
		if(idx[i].size()==0)
		{
			continue;
		}
		int Max = idx[i][0];
		for(int j=1;j<idx[i].size();j++)
		{
			Max = max(Max, idx[i][j] - idx[i][j-1] - 1);
			//cout << idx[i][j] - idx[i][j-1] - 2 << '\n';
		}
		Max = max(Max, (int)(s.length()) - 1 - idx[i][idx[i].size()-1]);
		res = min(res,Max);
	}

	cout << res << '\n';

	return 0;
}