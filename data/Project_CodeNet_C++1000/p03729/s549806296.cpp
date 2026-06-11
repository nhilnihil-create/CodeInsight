#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main(void)
{
	char a[11],b[11],c[11],x,y,z;
	scanf("%s %s %s",a,b,c);
	x=strlen(a);
	y=strlen(b);
	z=strlen(c);
	if(a[x-1]==b[0]&&b[y-1]==c[0]) printf("YES\n");
	else printf("NO\n");
	return 0;
}
