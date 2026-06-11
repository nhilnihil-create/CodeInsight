#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;

int n,p[100005];


int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&p[i]);
	int ans=0,tmp=0;
	for (int i=1;i<=n;i++) 
	if (p[i]!=i)
	{
		ans+=(tmp+1)>>1;
		tmp=0;
	}else tmp++;
	ans+=(tmp+1)>>1;
	printf("%d",ans);
	return 0;
}