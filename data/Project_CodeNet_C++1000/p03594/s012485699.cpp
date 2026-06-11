#include<cstdio>
using namespace std;
const int ch[4]={'R','Y','G','B'}; 
int n,m,k;
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1;i<=n;i++)
	{
	  for (int j=1;j<=m;j++)
	  {
	  	 int x=(m+i+j)/k%2,y=(m+i-j)/k%2;
	  	 printf("%c",ch[x*2+y]);
	  } 
	  puts("");
	}
	return 0;
} 