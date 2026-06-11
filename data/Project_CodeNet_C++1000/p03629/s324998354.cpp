#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
vector<int>pat[202020];
int dat[26][202020];
int dp[202020];
bool isok[202020];
int main()
{
	string s;
	cin >> s;
	int num = s.size();
	reverse(s.begin(), s.end());
	s.push_back('#');
	reverse(s.begin(), s.end());
	s.push_back('#');
	for (int i = 0; i < 26; i++)
	{
		dat[i][num + 1] = num + 1;
		for (int j = num + 1; j >= 1; j--)
		{
			if (s[j] == 'a' + i)dat[i][j - 1] = j;
			else dat[i][j - 1] = dat[i][j];
		}
	}
	fill(dp, dp + num + 10, 1000000000);
	dp[0] = 0;
	for (int i = 0; i <= num; i++)
	{
		for (int j = 0; j < 26; j++)
		{
			dp[dat[j][i]] = min(dp[dat[j][i]], dp[i] + 1);
			pat[dat[j][i]].push_back(i);
		}
	}
	isok[num + 1] = true;
	for (int i = num + 1; i >= 0; i--)
	{
		if (!isok[i])continue;
		for (int j = 0; j < pat[i].size(); j++)
		{
			if (dp[i] == dp[pat[i][j]] + 1)isok[pat[i][j]] = true;
		}
	}
	string ans;
	int now = 0;
	for (;;)
	{
		char c;
		for (int j = 0; j < 26; j++)
		{
			if (isok[dat[j][now]] && dp[now] + 1 == dp[dat[j][now]])
			{
				now = dat[j][now];
				c = 'a' + j;
				break;
			}
		}
		ans.push_back(c);
		if (now == num + 1)break;
	}
	cout << ans << endl;
}