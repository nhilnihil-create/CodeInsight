#include<cstdio> 
#include<cstring>
using namespace std;
const int N=200004;
const int T=100001;
int a[N];
int main()
{
	int t;
	memset(a,0,sizeof(a));
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		int x;
		scanf("%d",&x);
		a[T+x-1]++;a[T+x]++;a[T+x+1]++;
	}
	int max=0;
	for(int i=0;i<N;i++)
	{
		if(a[i]>max) max=a[i];
	}
	printf("%d\n",max);
}