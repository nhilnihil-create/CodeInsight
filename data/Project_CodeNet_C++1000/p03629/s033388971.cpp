#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;
struct Xam{
	int a[26],par;
}xam[200010];int last[26];
char s[200010];
void addxam()
{
	int len=strlen(s+1);
	for(int i=0;i<26;i++) last[i]=1;
	for(int i=1;i<=len;i++)
	{
		int p=i+1,c=s[i]-'a';
		for(int j=0;j<26;j++)
			for(int k=last[j];k&&!xam[k].a[c];k=xam[k].par) xam[k].a[c]=p;
		xam[p].par=last[c];last[c]=p;
	}
}
int son[200010],len[200010];
void dfs(int x)
{
	if(son[x]!=-1) return;
	if(!x) {son[x]=0,len[x]=0;return;}
	for(int i=0;i<26;i++)
	{
		int y=xam[x].a[i];
		//printf("%d->%d\n",x,y);
		dfs(y);
		if(son[x]==-1||len[y]<len[xam[x].a[son[x]]]) son[x]=i,len[x]=len[y]+1;
	}
	//printf("%d %d %d\n",x,son[x],len[x]);
	//if(x==1) printf("fuck:%d\n",xam[1].a[1]);
}
void print(int x)
{
	if(!x) return;
	printf("%c",son[x]+'a');
	print(xam[x].a[son[x]]);
}
int main()
{
	scanf("%s",s+1);
	addxam();
	memset(son,-1,sizeof(son));
	dfs(1);print(1);
}