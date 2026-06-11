#include<cstdio>
#include<algorithm>
using namespace std;

int a[100005];
int main()
{
	int n,Max=-1,Min=100005,k=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),Min=min(Min,a[i]),Max=max(Max,a[i]);
	if(Max-Min>1) return !printf("No");
	if(Max==Min)
	{
		if(Max==n-1) return !printf("Yes");
		if(n>=2*Max) return !printf("Yes");
		return !printf("No");
	}
	for(int i=1;i<=n;i++) if(a[i]==Max) k++;
	int M=Max-(n-k);
	if(M>0&&k>=2*M) return !printf("Yes");
	return !printf("No");
}