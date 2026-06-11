#include<bits/stdc++.h>

using namespace std;
#define int            long long
#define f(i,n)        for(int i=0;i<(n);++i)
#define fa(i,a,n)     for(int i=a;i<=(n);++i)
#define fd(i,a,n)     for(int i=a;i>=(n);--i)
#define tc 			  int t;cin>>t;f(testcase,t)
#define pii             pair<int,int>
void c_p_c() {

	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

}
int dp[51][1000][51];
int ways(int n, int sum, int count, vector<int>& a, int &av ) {
	if (n < 0)
		return 0;

	if (n == 0) {
		if (count == 0)
			return 0;
		int remainder = sum % count;
		if (remainder != 0)
			return 0;
		if (remainder == 0)
		{
			if (sum / count == av)
				return 1;
		}

	}
	if (dp[n][sum][count] != -1)
		return dp[n][sum][count];
	int pick = ways(n - 1, sum + a[n], count + 1, a, av);
	int dpick = ways(n - 1, sum, count, a, av);
	int total = pick + dpick;
	return dp[n][sum][count] = total;
}
int32_t main() {

	c_p_c();
	int n, av;
	cin >> n >> av;
	vector<int> a;
	a.resize(n + 1);
	a[0] = -1;
	fa(i, 1, n)
	cin >> a[i];
	memset(dp, -1, sizeof(dp));
	cout << ways(n, 0, 0, a, av);



	return 0;
}
