#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	vector<ll>sum[4];
	ll n,w;
	cin>>n>>w;
	ll w1,v;
	cin>>w1>>v;
	
	sum[0].push_back(v);
	for(int i=1;i<n;i++)
	{
		ll w,va;
		cin>>w>>va;
		sum[w-w1].push_back(va);

	}
	for(int i=0;i<4;i++)
		sort(sum[i].begin(),sum[i].end(),greater<ll>());
	for(int i=0;i<4;i++)
	{
		for(int j=1;j<sum[i].size();j++)
		{
			sum[i][j] +=sum[i][j-1];
		}
	}
	ll val=0;
	for(int i=0;i<=sum[0].size();i++)
	{
		for(int j=0;j<=sum[1].size();j++)
		{
			for(int k=0;k<=sum[2].size();k++)
			{
				for(int l=0;l<=sum[3].size();l++)
				{
					if(i*w1+j*(w1+1)+k*(w1+2)+l*(w1+3)<=w)
					{
						ll v=0;
						if(i>0)
							v += sum[0][i-1];
						if(j>0)
							v += sum[1][j-1];
						if(k>0)
							v += sum[2][k-1];
						if(l>0)
							v += sum[3][l-1];
						if(v>val)
							val=v;
					}
				}
			}
		}
	}
	cout<<val<<"\n";
}
