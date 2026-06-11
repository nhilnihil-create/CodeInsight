#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<iomanip>
#include<set>
#include<queue>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<pair<int,int>> x(n);
	vector<int> xx(n);
	for(int i=0;i<n;i++)
	{
		int tmp;
		cin >> tmp;
		x[i]=make_pair(tmp,i+1);
		xx[i]=tmp;
	}

	sort(x.begin(),x.end());

	vector<int> ans(n*n+1,0);
	int space=0;
	int now=0;
	for(int i=0;i<n;i++)
	{
		ans[x[i].first-1]=x[i].second;
		space+=x[i].first-now;
		now=x[i].first;
		if(space<x[i].second)
		{
			cout << "No" << endl;
			return 0;
		}
		space-=x[i].second;
	}
	now=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<x[i].second-1;j++)
		{
			while(ans[now]!=0)
				now++;
			ans[now]=x[i].second;
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=x[i].second;j<n;j++)
		{
			while(ans[now]!=0)
				now++;
			ans[now]=x[i].second;
		}
	}
	bool flag=true;
	vector<int> cnt(n,0);
	for(int i=0;i<n*n;i++)
	{
		cnt[ans[i]-1]++;
		if(xx[ans[i]-1]==i+1)
		{
			//cout << cnt[ans[i]-1] << " " << ans[i] << endl;
			if(cnt[ans[i]-1]!=ans[i])
				flag=false;
		}
	}
	if(flag)
	{
		cout << "Yes" << endl;
		for(int i=0;i<n*n;i++)
			cout << ans[i] << (i==n*n-1 ? "\n":" ");
	}
	else
		cout << "No" << endl;
	
}