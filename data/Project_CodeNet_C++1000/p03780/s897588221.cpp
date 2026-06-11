#include <iostream>
#include <bitset>
#define ll long long
using namespace std;
const int MDSZ = 1;
const int MD[4] = {503, 1069696919, 701, 1018199999};
int n, k, ar[5001] = {}, rs = 0, a = 0, b = 0;
int dp[5001][MDSZ] = {};
void outDP(string s)
{
	cout << s << " : \n";
	for (int i = 0; i < k; i++)
	{
		cout << i << " " << dp[i][0] << "\n";
	}
}
int main()
{
	ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> k; rs = n;
	for (int i = 0; i < n; i++) 
	{
		cin >> ar[i];
		if (ar[i] >= k) {a++;}
	}
	rs -= a;
	for (int i = 0; i < MDSZ; i++) {dp[0][i] = 1;}
	for (int i = 1; i <= n; i++)
	{
		for (int j = k - 1; j >= ar[i - 1]; j--) 
		{
			for (int kk = 0; kk < MDSZ; kk++)
			{
				dp[j][kk] += dp[j - ar[i - 1]][kk];
				dp[j][kk] %= MD[kk];
			}
		}
	}
	//outDP("ALL");
	for (int i = 1; i <= n; i++)
	{
		if (ar[i - 1] < k)
		{
			for (int j = ar[i - 1]; j < k; j++)
			{
				for (int kk = 0; kk < MDSZ; kk++)
				{
					dp[j][kk] -= dp[j - ar[i - 1]][kk];
					dp[j][kk] %= MD[kk];
					dp[j][kk] = (dp[j][kk] + MD[kk]) % MD[kk];
				}
			}
			//outDP("REM" + to_string(i));
			for (int j = k - ar[i - 1]; j < k; j++)
			{
				bool ck = 1;
				for (int kk = 0; kk < MDSZ; kk++) {ck &= (dp[j][kk] > 0);}
				if (ck) {rs--; break;}
			}
			for (int j = k - 1; j >= ar[i - 1]; j--) 
			{
				for (int kk = 0; kk < MDSZ; kk++)
				{
					dp[j][kk] += dp[j - ar[i - 1]][kk];
					dp[j][kk] %= MD[kk];
				}
			}
			//outDP("FIX" + to_string(i));
		}
	}
	cout << rs << "\n";
	return 0;
}