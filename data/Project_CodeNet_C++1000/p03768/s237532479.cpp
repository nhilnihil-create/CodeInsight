#include<cstdio>
#include<vector>
#include<map>
using namespace std;
vector<int> gra[100001];
int O[100001],dis[100001],aimc[100001],color[100001],alr_mxdis[100001];
void dfs(int wil,int lefdis,int aim)
{
	if(lefdis<=alr_mxdis[wil])
		return;
	alr_mxdis[wil]=lefdis;
	if(!color[wil])
		color[wil]=aim;
	if(!lefdis)
		return;
	for(int i=0;i<gra[wil].size();i++)
		dfs(gra[wil][i],lefdis-1,aim);
}
int main()
{
	int n,m,tim,i;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		alr_mxdis[i]=-1;
	for(i=1;i<=m;i++)
	{
		int s,e;
		scanf("%d%d",&s,&e);
		gra[s].push_back(e);
		gra[e].push_back(s);
	}
	scanf("%d",&tim);
	for(i=1;i<=tim;i++)
		scanf("%d%d%d",O+i,dis+i,aimc+i);
	for(i=tim;i;i--)
		dfs(O[i],dis[i],aimc[i]);
	for(i=1;i<=n;i++)
		printf("%d\n",color[i]);
	return 0;
}
/*1
7 7
1 2
1 3
1 4
4 5
5 6
5 7
2 3
2
6 1 1
1 2 2
*/
/*2
14 10
1 4
5 7
7 11
4 10
14 7
14 3
6 14
8 11
5 13
8 3
8
8 6 2
9 7 85
6 9 3
6 7 5
10 3 1
12 9 4
9 6 6
8 2 3
*/