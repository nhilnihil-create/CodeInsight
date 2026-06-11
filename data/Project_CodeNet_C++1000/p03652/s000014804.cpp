#include<bits/stdc++.h>
using namespace std;
int n,m,sp[305][305],hh[305],mx,pos,st[305],ans=1000;
bitset<305>del;
vector<int>v;
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		st[i]=1;
		for(int j=1;j<=m;j++)
		{
			scanf("%d",&sp[i][j]);
		}
		hh[sp[i][1]]++;
	}
	for(int i=m;i>0;i--)
	{
		mx=0;
		for(int j=1;j<=m;j++)
		{
			if(hh[j]>=mx)mx=hh[j],pos=j;
			//printf("%d ",hh[j]);
		}	
		//printf("-------------------------\n");
		del[pos]=true;
		hh[pos]=0;
		//if(mx==0)break;
		//printf("////%d\n",mx);
		ans=min(ans,mx);
		for(int j=1;j<=n;j++)
		{
			if(del[sp[j][st[j]]])
			{
				while(del[sp[j][st[j]]])
				{
					st[j]++;	
				}
				hh[sp[j][st[j]]]++;	
			}
		}
	}
	printf("%d",ans);
}
