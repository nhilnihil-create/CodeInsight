#include<cstdio>
using namespace std;
int a,b;
int main()
{
	scanf("%d%d",&a,&b);
	if(a+b<10) printf("%d",a+b);
	else printf("error");
	return 0;
}