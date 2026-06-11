#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int mod = 1000 * 1000 * 1000 + 7;
const int ob = (mod + 1) >> 1;
int dp[5001][5001];
void add(int &a , int b)
{
	a = a + b >= mod ? a + b - mod : a + b;
}
int mult(int a , int b)
{
	return (a * (LL)b) % mod;
}
int main()
{
	string s;
	int N;
	cin >> N >> s;
	dp[0][0] = 1;
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j <= i; j++)
		{
			add(dp[i + 1][j + 1] , mult(dp[i][j] , 2));

			add(dp[i + 1][max(j - 1 , 0)] , dp[i][j]);
		}
	}
	int ans = dp[N][s.size()];
	for(int i = 0; i < s.size(); i++)
		ans = mult(ans , ob);
	cout << ans;
	//freopen("In.txt" , "r" , stdin);
}


