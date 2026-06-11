#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <queue>
#include <deque>
#include <map>
#include <stack>
#include<bitset>
#include<list>
#include<cassert>
#include<numeric>
 
using namespace std;

const int N = 2 * 1000 + 5;
vector<long long> a;
long long n, x;
long long dp[N][N];

int main()
{
	cin >> n >> x;
	for (int i = 0; i < n; i++)
	{
		long long tmp;
		cin >> tmp;
		a.push_back(tmp);
	}
	long long ans = 1000 * 1000 * 1000 * 1ll * 1000 * 1000 * 1000;
	for (int i = 0; i < n; i++)
		dp[0][i] = a[i];
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			dp[i][j] = min(a[((j - i) + n) % n], dp[(i - 1 + n) % n][j]); 
		}
	}
	for (int i = 0; i < n; i++)
	{
		long long tmp = 0;
		for (int j = 0; j < n; j++)
		{
			tmp += dp[i][j];
		}
		ans = min(ans, i * x + tmp);
	}
	cout << ans << endl;

}
