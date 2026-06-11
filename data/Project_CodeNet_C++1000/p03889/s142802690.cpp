#include<algorithm>
#include<cstdio>
#include<cstring>
#define N 100010
using namespace std;
char a[N],b[N];
int len;
signed main(int argc,char **argv)
{
	scanf("%s",&a);len=strlen(a);
	for(int i=0;i<len;++i)b[len-i-1]=a[i];
	for(int i=0;i<len;++i)
		if(b[i]=='b')b[i]='d';
		else if(b[i]=='d')b[i]='b';
		else if(b[i]=='p')b[i]='q';
		else b[i]='p';
	for(int i=0;i<len;++i)
	if(a[i]!=b[i]){printf("No");return 0;}
	printf("Yes");
	return 0;
}