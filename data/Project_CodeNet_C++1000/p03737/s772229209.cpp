#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main(void)
{
	char a[10],b[10],c[10];
	scanf("%s %s %s",a,b,c);
	if(a[0]>=97&&a[0]<=122) printf("%c",a[0]-32);
	if(b[0]>=97&&b[0]<=122) printf("%c",b[0]-32);
	if(c[0]>=97&&c[0]<=122) printf("%c\n",c[0]-32);
	return 0;
}
