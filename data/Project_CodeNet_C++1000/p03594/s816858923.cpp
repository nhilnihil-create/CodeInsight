#include <cstdio>
#include <cstring>
using namespace std;
int n,m,k;
main()
{
	char s[4]={'R','Y','G','B'};
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1;i<=n;i++,puts(""))
		for (int j=1;j<=m;j++)
		{
			int pos=0;
			pos|=(i+j)/k%2;
			pos|=(n-i+j-1)/k%2*2;
			printf("%c",s[pos]);
		}
}