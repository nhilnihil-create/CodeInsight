#include <iostream>
#include <algorithm>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	int n,m,a,b;
	cin>>n>>m;
	int box[n],vis[n]={0};
	for(int i=0;i<n;i++)
	box[i]=1;
	vis[0]=1;
	for(int i=0;i<m;i++)
	{
		cin>>a>>b;
		--a,--b;
		--box[a],++box[b];
		if(vis[a])
		{
			if(box[a])vis[b]=1;
			else vis[a]=0,vis[b]=1;
		}
	}
	int ans=0;
	for(int i=0;i<n;i++)
	if(vis[i])ans++;
	cout<<ans;
	return 0;
}