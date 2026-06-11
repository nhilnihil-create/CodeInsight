#include <cstdio>
#include <cstring>
const int S=200030;
int n,k,su=0,res=0,c[S],f[S],nx[S][26],pre[S],id=1;
char y[S];
inline int mi(int a,int b){return a<b?a:b;}
int main()
{
	scanf("%s",y+1);
	n=strlen(y+1);
	for (int i=0;i<26;i++) nx[n+1][i]=n+1;f[n+1]=1;
	for (int j=n;j;--j)
	{
		for (int i=0;i<26;i++) nx[j][i]=nx[j+1][i];
		nx[j][y[j]-'a']=j;
	}
//	for (int j=n;j;--j)
//	{
//		for (int i=0;i<26;i++) printf("%d ",nx[j][i]);
//		puts("");
//	}
	for (int i=n;i;i--)
	{
		f[i]=1<<30;
		for (int j=0;j<26;j++)
			f[i]=mi(f[i],f[nx[i][j]+1]+1);
//		printf("%d ",f[i]);
	}
	for (int i=1;i<=n;)
	{
		int j;
		for (j=0;j<26;j++)
			if (f[i]==f[nx[i][j]+1]+1)
				break;
		printf("%c",j+'a');
		i=nx[i][j]+1;
	}
	return 0;
}
