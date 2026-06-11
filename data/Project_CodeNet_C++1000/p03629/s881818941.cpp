#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;



string s;
int n;

typedef pair<char,int> P;

int dp[200010];

int before[26];

int main()
{
	fill(dp,dp + 200010,1e9);
	cin >> s;
	n = s.length();


	dp[n + 1] = 0;
	dp[n] = 1;

	vector<P> to(n + 1);

	to[n] = P('a' , n + 1);

	fill(before , before + 26 , n + 1);


	for(int i = n - 1;i >= 0;i--)
	{
		before[s[i] - 'a'] = i + 1;

		for(int j = 0;j < 26;j++)
		{
			if(dp[before[j]] + 1 < dp[i])
			{
				dp[i] = dp[before[j]] + 1;
				to[i] = P('a' + j , before[j]);
			}
		}
	}

	int now = 0;

	while(now < n + 1)
	{
		cout << to[now].first;
		now = to[now].second;
	}

	return 0;





}
