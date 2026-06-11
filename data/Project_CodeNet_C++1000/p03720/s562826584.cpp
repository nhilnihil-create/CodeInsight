#include<cstdio>
#include<algorithm>
using namespace std;
int main(void)
{
	int n,m,a,b,i,c[51]={0};
	scanf("%d%d",&n,&m);
	for(i=0;i<m;i++){
		scanf("%d%d",&a,&b);
		c[a]++;
		c[b]++;
	}
	for(i=1;i<=n;i++){
		printf("%d\n",c[i]);
	}
	return 0;
}
