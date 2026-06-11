#include<iostream>
#include<algorithm>
using namespace std;
bool used[333];
int n,m;
int a[333][333];
int cnt[333];
int id[333];
main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)cin>>a[i][j];
		cnt[a[i][0]]++;
	}
	int ans=n;
	for(int ccc=m;ccc--;)
	{
		int mi=-1;
		for(int i=1;i<=m;i++)
		{
			if(cnt[i]==0)continue;
			if(mi<0||cnt[mi]<cnt[i])mi=i;
		}
		ans=min(ans,cnt[mi]);
		used[mi]=1;
		if(ccc)
		{
			for(int i=0;i<n;i++)
			{
				cnt[a[i][id[i]]]--;
				for(;used[a[i][id[i]]];id[i]++);
				cnt[a[i][id[i]]]++;
			}
		}
	}
	cout<<ans<<endl;
}