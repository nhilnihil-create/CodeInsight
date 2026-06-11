#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=200005;
int n,nx[maxn][26],tot,lnk[maxn],son[maxn],nxt[maxn],dep[maxn];char S[maxn];
inline void add_e(int x,int y){tot++;son[tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;}
void DFS(int now)
{
	for(int i=lnk[now];i;i=nxt[i])
		{dep[son[i]]=dep[now]+1;DFS(son[i]);}
}
void Print(int now)
{
	if(now==n+1){putchar('\n');return;}
	for(int j=0;j<26;j++)
	{
		if(dep[nx[now][j]]==dep[now]-1)
		{
			putchar(j+'a');
			Print(nx[now][j]);
			return;
		}
	}
}
int main()
{
	scanf("%s",S+1);
	n=strlen(S+1);
	for(int i=0;i<26;i++) nx[n][i]=n+1;
	for(int i=n-1;i>=0;i--)
	{
		for(int j=0;j<26;j++)
		{
			if(S[i+1]==j+'a') nx[i][j]=i+1;
			else nx[i][j]=nx[i+1][j];
		}
	}
	for(int i=0;i<=n;i++)
	{
		int mx=0;
		for(int j=0;j<26;j++)
			mx=max(mx,nx[i][j]);
		add_e(mx,i);
	}
	DFS(n+1);
	Print(0);
	return 0;
}