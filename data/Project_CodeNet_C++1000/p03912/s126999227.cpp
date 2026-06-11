#include <bits/stdc++.h>

using namespace std;

priority_queue <int> pque[100001];
int cnt[100001];
int n,m,t;
int cnt2[100001];
int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	//ifstream cin("01-03.txt");

	cin >> n >> m;

	for(int i=0;i<n;i++)
	{
		cin >> t;
		cnt[t]++;
		//cnt2[t%m]++;
	}

	long long int res = 0;
	long long sum1 = 0;
	long long sum2 = 0;
	for(int i=1;i<=100000;i++)
	{
		if(i%m==0)
		{
			sum1 += cnt[i];
		}
		else
		{
			int t = (i%m);
			if(2*t==m)
			{
				sum2 += cnt[i];
			}
			else
			{
				if(cnt[i]%2==1)
				{
					cnt2[(i%m)]+=1;
					cnt[i]-=1;
				}
				if(cnt[i]!=0)
				{
					pque[(i%m)].push(cnt[i]);
				}
			}
		}
	}
	//cout << sum1 << ' ' << sum2 << '\n';
	res += (sum1/2);
	res += (sum2/2);

	for(int a=1;a<=(m/2);a++)
	{
		int b = m - a;
		if(a==b)
		{
			break;
		}
		//cout << a << ' ' << b << ' ' << cnt2[a] << ' ' << cnt2[b] << '\n';
		if(cnt2[a]<=cnt2[b])
		{
			res += cnt2[a];
			int x = cnt2[b] - cnt2[a];
			while(!pque[a].empty())
			{
				int y = pque[a].top();
				pque[a].pop();
				if(x<=y)
				{
					res += x;
					y-=x;
					pque[a].push(y);
					break;
				}
				x-=y;
				res += y;
			}
		}
		else
		{
			res += cnt2[b];
			int x = cnt2[a] - cnt2[b];
			while(!pque[b].empty())
			{
				int y = pque[b].top();
				pque[b].pop();
				if(x<=y)
				{
					res += x;
					y-=x;
					pque[b].push(y);
					break;
				}
				x-=y;
				res += y;
			}			
		}
	}

	for(int i=1;i<m;i++)
	{
		while(!pque[i].empty())
		{
			int now = pque[i].top();
			pque[i].pop();
			res += (now/2);
		}
	}

	cout << res << '\n';

	return 0;
}
