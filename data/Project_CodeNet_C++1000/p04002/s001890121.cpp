#include<bits/stdc++.h>
#define LL long long
using namespace std;

LL n,h,w,x,y,ans[10];
LL dx[9]={1,1,1,0,0,-1,-1,-1,0},dy[9]={-1,0,1,-1,1,-1,0,1,0};
map<pair<int,int>,int>Map;

int main()
{
	cin>>h>>w>>n;
	ans[0]=(h-2)*(w-2);
	for (int i=1; i<=n; ++i)
	{
		cin>>x>>y;
		for (int i=0; i<9; ++i)
		{
			LL X=x+dx[i],Y=y+dy[i];
			if (X<2 || X>h-1 || Y<2 || Y>w-1) continue;
			LL num=Map[make_pair(X,Y)]++;
			ans[num]--; ans[num+1]++;
		}
	}
	for (int i=0; i<=9; ++i) cout<<ans[i]<<endl;
}