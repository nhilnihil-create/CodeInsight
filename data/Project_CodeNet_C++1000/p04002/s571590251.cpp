#include <bits/stdc++.h>
using namespace std;
map<pair<int,int>,int> mapp;
int h,w,n,a[10];
int main()
{
	scanf("%d%d%d",&h,&w,&n);
	for(int i=1;i<=n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		for(int j=max(x-2,1);j<=min(h-2,x);j++)
		{
			for(int k=max(y-2,1);k<=min(w-2,y);k++)
			{
				mapp[pair<int,int>(j,k)]++;
			}
		}
	}
	int cnt=0;
	for(map<pair<int,int>,int>::iterator it=mapp.begin();it!=mapp.end();it++)
	{
		a[it->second]++;
		cnt++;
	}
	printf("%lld\n",(long long)(h-2)*(long long)(w-2)-cnt);
	for(int i=1;i<=9;i++) printf("%lld\n",(long long)a[i]);
	return 0;
}
