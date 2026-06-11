#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<complex>
#include<string>
#include<cstring>
using namespace std;
#define rep2(x,from,to) for(int x=(from);(x)<(to);(x)++)
#define rep(x,to) rep2(x,0,to)
#define INF 100000000
#define debug(x) cout<<#x<<": "<<x<<endl

#define all(x) x.begin(),x.end()
typedef pair<int,int> P;
typedef pair<int,P> PP;
int kesu[100000];
int n,m;
int ans;
int zen[100000];
int x[100006];
vector<int> hai[100000];
int main()
{
	cin>>n>>m;
	rep(i,n)
	{
		cin>>x[i];
		hai[(x[i]%m)].push_back(x[i]);
	}
	rep(i,m)
	{
		sort(hai[i].begin(),hai[i].end());
	}
	int kk;
	rep(i,m)
	{
		kk=hai[i].size();
		zen[i]=kk;
		rep(j,kk-1)
		{
			if(hai[i][j]==hai[i][j+1])
			{
				kesu[i]++;
				j++;
			}
		}
	}
	ans+=(zen[0]/2);
	if(m%2==0)
	{
		ans+=(zen[m/2]/2);
	}
	rep2(i,1,(m+1)/2)
	{
		if(zen[i]<zen[m-i])
		{
			ans+=zen[i];
			zen[m-i]-=zen[i];
			ans+=min(zen[m-i]/2,kesu[m-i]);
		}
		else
		{
			ans+=zen[m-i];
			zen[i]-=zen[m-i];
			ans+=min(zen[i]/2,kesu[i]);
		}
	}
	cout<<ans<<endl;
	return 0;
}