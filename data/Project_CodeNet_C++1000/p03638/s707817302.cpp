#include<bits/stdc++.h>
using namespace std;
int m[105][105],a[10050];
int main()
{
	int h,w,n,now1,now=0;
	cin>>h>>w>>n;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	now1=1;
	for (int i=0;i<h;i++)
	{
		if (i%2==0)
		{
			now=0;
			while (now!=w)
			{
				m[i][now]=now1;
				now++;
				a[now1]--;
				if (a[now1]==0)
					now1++;
			}
		}
		else
		{
			now=w-1;
			while(now!=-1)
			{
				m[i][now]=now1;
				now--;
				a[now1]--;
				if (a[now1]==0)
					now1++;
			}
		}
	}
	for (int i=0;i<h;i++)
	{
		for (int j=0;j<w;j++)
			cout<<m[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}