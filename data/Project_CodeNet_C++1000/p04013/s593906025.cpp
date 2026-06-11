#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>

#define rep(i,n) for(int i = 0;i < n;i++)
#define Rep(i,m,M) for(int i = m;i < M;i++)
#define print(var) cout<<#var" = "<<var<<endl;

typedef long long ll;

using namespace std;

typedef long long ll;
typedef vector<int> vint;
typedef vector<char> vchar;
typedef vector<vector<int>> vvint;

int main()
{
	int N, A;
	cin >> N >> A;
	vint x(N+1);
	int goal = A * N,S;
	rep(i, N)
	{
		cin >> x[i+1];
	}
//	cout << x[4] << endl;
	vector<vector<vector<long long>>> dp(N + 1, vector<vector<long long>>(goal + 1, vector<long long>(N + 1)));
	dp[0][0][0] = 1;
	rep(i, N)
	{
		dp[i][0][0] = 1;
	}
	for (int i = 1; i <= N;i++)
	{
	//	print(i)
		for (int j = 0; j <= goal; j++)
		{
	//		print(j)
				for (int k = 1; k <= N; k++)
				{
	//				print(k)
						//			cout << dp[i - 1][j][k];
						
						if (j - x[i] >= 0)
						{
			//				cout << '!' << endl;
							dp[i][j][k] = dp[i - 1][j][k] + dp[i - 1][j - x[i]][k - 1];
				//			print("end")
						}
						else
						{
				//			cout << '?' << endl;
							dp[i][j][k] = dp[i - 1][j][k];
				//			print("end")
						}
					
				}
		}
	}
/*	rep(i, N+1)
	{
		rep(j, goal+1)
		{
			rep(k, N+1)
			{
				if (dp[i][j][k] != 0)
				{
					cout << "dp[" << i << "][" << j << "][" << k << "] = " << dp[i][j][k] << endl;
				}
			}
		}
	}
	*/
	ll ans = 0;

	for(int i = 1;i<=N;i++)
	{
	//	print(i)
//		cout << "dp[" << N << "][" << (i + 1) * A << "][" << i + 1 << "] = " << dp[N][(i + 1) * A][i + 1] << endl;
			ans += dp[N][i*A][i];
	//	print(ans)
	}
	cout << ans << endl;
//	print(dp[0][16][2])
}
