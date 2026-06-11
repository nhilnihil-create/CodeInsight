#include<cstdio>
using namespace std;
long long i,j,n,m,add,mo;
int main()
{
	scanf("%lld",&m);
	puts("50");
	add=m/50;
	mo=m%50;
	if (!mo)
	{
		for (i=1;i<=50;++i)
			printf("%lld ",49+add);
		return 0;
	}
	for (i=1;i<=50-mo;++i)
		printf("%lld ",50-mo-1+add);
	for (i=1;i<=mo;++i)
		printf("%lld ",50-mo+i+add);
	return 0;
}