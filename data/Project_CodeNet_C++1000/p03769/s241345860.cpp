#include <map>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 506
using namespace std;
int m,p1,p2,a[N],b[N],ans[N];long long n;
int main()
{
	scanf("%lld",&n);n++;m=100;
	while(n>1){
		if(n&1)n--,a[++p1]=m--;
		else n>>=1,b[++p2]=m--;
	}
	printf("%d\n",2*(p1+p2));
	for(int i=1;i<=p1;i++)printf("%d ",a[i]);
	for(int i=p2;i>=1;i--)printf("%d ",b[i]);
	for(int i=100-p1-p2+1;i<=100;i++)printf("%d ",i);puts("");
}