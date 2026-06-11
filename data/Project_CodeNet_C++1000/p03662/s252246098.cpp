#include<bits/stdc++.h>
using namespace std;
int n,fat[100050],num[100050];
vector <int> V[100050];
int dfs(int now,int f)
{
	fat[now]=f;
	int tot=1;
	for(int i=0;i<V[now].size();i++)
		if(V[now][i]!=f)tot+=dfs(V[now][i],now);
	return num[now]=tot;
}
int main()
{
	cin>>n;
	for(int i=1;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		V[x].push_back(y);
		V[y].push_back(x);
	}
	num[1]=dfs(1,1);
	int z=n,sum=0;
	while(fat[z]!=z)
	{
		sum++;
		z=fat[z];
	}
	z=n;
	for(int i=1;i<=(sum-1)/2;i++)z=fat[z];
	if(num[z]>=n-num[z])cout<<"Snuke";
	else cout<<"Fennec";
	return 0;
} 