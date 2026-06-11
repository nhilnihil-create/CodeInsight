#include<cstdio>
#include<algorithm>
using namespace std;
int main(void)
{
	int x,a,b;
	scanf("%d%d%d",&x,&a,&b);
	a=x-a;
	b=x-b;
	if(a<0) a*=-1;
	if(b<0) b*=-1;
	if(a<=b) printf("A\n");
	else printf("B\n");
	return 0;
}
