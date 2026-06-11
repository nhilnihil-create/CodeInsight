#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
const int N=200005;
struct qq
{
	int son[26];
	int par;
}tr[N];
int last[26];
int num=0;
char ss[N];
void add (int x)
{
	num++;
	for (int u=0;u<26;u++)
		for (int i=last[u];i!=0&&tr[i].son[x]==0;i=tr[i].par)
			tr[i].son[x]=num;
	tr[num].par=last[x];
	last[x]=num;
}
int son[N],len[N];
void dfs (int x)
{
	if (son[x]!=-1) return ;
	if (x==0) 	{len[x]=son[x]=0;return ;}
	for (int u=0;u<26;u++)
	{
		int y=tr[x].son[u];
		dfs(y);
		if (son[x]==-1||len[y]<len[tr[x].son[son[x]]]) son[x]=u;
	}
	len[x]=len[tr[x].son[son[x]]]+1;
}
void print (int x)
{
	if (x==0) return ;
	//printf("YES:%d %d %d\n",x,son[x],tr[x].son[son[x]]);
	printf("%c",son[x]+'a');
	print(tr[x].son[son[x]]);
}
int main()
{
	for (int u=0;u<26;u++) last[u]=1;num=1;
	scanf("%s",ss+1);int len=strlen(ss+1);
	for (int u=1;u<=len;u++)	add(ss[u]-'a');
	memset(son,-1,sizeof(son));
	dfs(1);
	//printf("%d %d\n",son[1],tr[1].son[0]);
	print(1);
	return 0;
}