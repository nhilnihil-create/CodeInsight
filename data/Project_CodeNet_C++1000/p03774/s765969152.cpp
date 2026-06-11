#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	vector<pair<int,int>> students,chk_pts;
	for(int i=0;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		students.push_back({x,y});
	}
	for(int i=0;i<m;i++)
	{
		int x,y;
		cin>>x>>y;
		chk_pts.push_back({x,y});
	}
	for(int i=0;i<n;i++)
	{
		int dis=1e9;
		int cur=-1;
		for(int j=0;j<m;j++)
		{
			int d=abs(students[i].first-chk_pts[j].first)+abs(students[i].second-chk_pts[j].second);
			if(dis>d)
			{
				dis=d;
				cur=j+1;
			}
		}
		cout<<cur<<endl;
	}
	return 0;

}
