#include <bits/stdc++.h>

using namespace std;

bool dp[5001][5001];
bool dp2[5001][5001];

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n,k,t;
	vector <int> v;

	cin >> n >> k;
	for(int i=0;i<n;i++)
	{
		cin >> t;
		t = min(t,k);
		v.push_back(t);
	}

//	sort(v.begin(),v.end());

	memset(dp,false,sizeof(dp));
	dp[0][0] = true;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<=k;j++)
		{
			if(dp[i][j]==false)
			{
				continue;
			}
			dp[i+1][j] = true;
			if(j + v[i] <= k)
			{
				dp[i+1][j+v[i]] = true;
			}
		}
	}


	memset(dp2,false,sizeof(dp2));
	dp2[n][0] = true;
	for(int i=n-1;i>=0;i--)
	{
		for(int j=0;j<=k;j++)
		{
			if(dp2[i+1][j]==false)
			{
				continue;
			}
			dp2[i][j] = true;
			if(j + v[i] <= k)
			{
				dp2[i][j+v[i]] = true;
			}
		}
	}

	int res = 0;
	for(int i=0;i<n;i++)
	{
		bool ok = false;
		for(int j=0;j<k;j++)
		{
			if(dp[i][j]==true || dp2[i+1][j]==true)
			{
				if(j+v[i] >= k)
				{
					ok = true;
					break;
				}
			}
		}
		for(int j=0;j<=k-v[i];j++)
		{
			if(dp[i][j]==true && dp2[i+1][k-v[i]-j]==true)
			{
				ok = true;
				break;
			}
		}
		if(!ok)
		{
			res++;
		}
	}
	cout << res << '\n';

	return 0;
}
