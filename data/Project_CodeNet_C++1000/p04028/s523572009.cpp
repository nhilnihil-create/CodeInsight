#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long i64;
typedef i64 ll;


i64 bin[5010];
i64 MOD = 1e9 + 7;
ll inv_mod( ll a, ll m = MOD )
{
  ll b, x, u, q, abs_m, tmp; 

  abs_m = ( m < 0 ) ? -m : m;
  b = m; x = 1; u = 0; 
  while ( b > 0 ) {
    q = a / b; 
    tmp = u; u = x - q * u; x = tmp;
    tmp = b; b = a - q * b; a = tmp;
  }

  return ( x < 0 ) ? abs_m + x : x;
}

i64 mod(i64 num)
{
	return num % MOD;
}

i64 dp[5010][5010];

int n;
int m;
string s;

int main()
{
	cin >> n >> s;
	int m = s.length();

	int cou = n - m;

	bin[0] = 1;

	for(int i = 1;i <= 5000;i++)
	{
		bin[i] = mod(bin[i - 1] * 2);
	}

	dp[0][0] = 1;
	//n time"s
	for(int i = 1;i <= n;i++)
	{
		for(int j = 0;j <= n;j++)
		{
			if(j == 0)
			{
				dp[i][j] = mod(dp[i - 1][j] + dp[i - 1][j + 1]);
			}
			else
			{
				dp[i][j] = mod(dp[i - 1][j - 1] * 2 + dp[i - 1][j + 1]);
			}
			////cout << i << " " << j << "=" << dp[i][j] << endl;
		}
	}

	//cout << dp[n][m] << "/" << inv_mod(bin[m]) << endl;

	cout << mod(dp[n][m] * inv_mod(bin[m])) << endl;
}
