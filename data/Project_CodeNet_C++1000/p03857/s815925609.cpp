#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
#include<map>
#define MAXN 200000
using namespace std;
typedef pair<int,int> PII;
map<PII,int> mp;
int setfa[2][MAXN+5];
void Init()
{
	for(int i=0;i<=MAXN+3;i++)
		setfa[0][i]=setfa[1][i]=i;
}
int Findfa(int x,int typ)
{
	if(setfa[typ][x]==x)
		return x;
	return setfa[typ][x]=Findfa(setfa[typ][x],typ);
}
void Union(int x,int y,int typ)
{
	int fx=Findfa(x,typ),fy=Findfa(y,typ);
	if(fx==fy)
		return;
	setfa[typ][fx]=fy;
}
int main()
{
	Init();
	int N,K,L;
	scanf("%d %d %d",&N,&K,&L);
	int x,y;
	for(int i=1;i<=K;i++)
	{
		scanf("%d %d",&x,&y);
		Union(x,y,0);
	}
	for(int i=1;i<=L;i++)
	{
		scanf("%d %d",&x,&y);
		Union(x,y,1);
	}
	for(int i=1;i<=N;i++)
	{
		int a=Findfa(i,0),b=Findfa(i,1);
		mp[PII(a,b)]++;
	}
	int Ans;
	for(int i=1;i<=N;i++)
	{
		int a=Findfa(i,0),b=Findfa(i,1);
		Ans=mp[PII(a,b)];
		if(i==1)
			printf("%d",Ans);
		else
			printf(" %d",Ans);
	}
	printf("\n");
	return 0;
}