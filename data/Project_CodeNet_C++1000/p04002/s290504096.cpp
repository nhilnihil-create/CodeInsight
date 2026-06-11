#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#include<set> 
#define sqr(x) (x)*(x)
using namespace std;
long long n,m,k,i,j,l,ans[15],x[100005],y[100005];
int dx[9]={0,-1,-1,-1,0,0,1,1,1},dy[9]={0,-1,0,1,-1,1,-1,0,1};
set<pair<int,int>/**/> s,vis;
int main()
{
	ios::sync_with_stdio(0);
	cin>>n>>m>>k;
	for (i=1;i<=k;i++)
	{
		cin>>x[i]>>y[i];
		s.insert(make_pair(x[i],y[i]));
	}
	ans[0]=(n-2)*(m-2);
	for (i=1;i<=k;i++)
	{
		for (j=0;j<=8;j++)
		{
			int xx=x[i]+dx[j],yy=y[i]+dy[j];
			if (xx<2||xx>=n||yy<2||yy>=m) continue;
			if (vis.count(make_pair(xx,yy))) continue;
			vis.insert(make_pair(xx,yy));
			int now=0;
			for (l=0;l<=8;l++)
			{
				int xxx=xx+dx[l],yyy=yy+dy[l];
				now+=s.count(make_pair(xxx,yyy));
			}
			//cerr<<xx<<' '<<yy<<' '<<now<<endl;
			/*if (now==1)
			{
				cerr<<xx<<' '<<yy<<endl;
			}*/
			ans[0]--;
			ans[now]++;
		}
	}
	/*int xx,yy;
	for (xx=2;xx<n;xx++)
	{
		for (yy=2;yy<m;yy++)
		{
			int now=0;
			for (l=0;l<=8;l++)
			{
				int xxx=xx+dx[l],yyy=yy+dy[l];
				now+=s.count(make_pair(xxx,yyy));
			}
			//cerr<<xx<<' '<<yy<<' '<<now<<endl;
			if (now==1)
			{
				cerr<<xx<<' '<<yy<<endl;
			} 
		}
	}*/
	for (i=0;i<=9;i++) cout<<ans[i]<<endl;
	return 0;
}