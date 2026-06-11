#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

char dp[100010];
int n;
string str;

bool check()
{
	for(int i = 2;i <= n+1;i++)
	{
		if(dp[i-2] == 'S')
		{
			if(dp[i-1] == 'S')
			{
				if(str[i-1] == 'o')dp[i] = 'S';
				else dp[i] = 'W';
			}
			else
			{
				if(str[i-1] == 'o')dp[i] = 'W';
				else dp[i] = 'S';
			}
		}
		else
		{
			if(dp[i-1] == 'S')
			{
				if(str[i-1] == 'o')dp[i] = 'W';
				else dp[i] = 'S';
			}
			else
			{
				if(str[i-1] == 'o')dp[i] = 'S';
				else dp[i] = 'W';
			}
		}
	}
	if(dp[0]==dp[n]&&dp[1]==dp[n+1])
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	cin >> n;
	cin >> str;
	str += str[0];
	str += str[1];

	dp[0] = 'S';dp[1] = 'S';
	if(check()){rep(i,n)cout << dp[i];cout << endl;return 0;}
	dp[0] = 'S';dp[1] = 'W';
	if(check()){rep(i,n)cout << dp[i];cout << endl;return 0;}
	dp[0] = 'W';dp[1] = 'S';
	if(check()){rep(i,n)cout << dp[i];cout << endl;return 0;}
	dp[0] = 'W';dp[1] = 'W';
	if(check()){rep(i,n)cout << dp[i];cout << endl;return 0;}

	cout << -1 << endl;

	return 0;
}
