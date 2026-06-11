#include<cstdio>
#include<iostream>
#include<queue>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<set>
#include<cstdlib>
#include<stack>
#include<ctime>
#include<map>
#include<list>
using namespace std;

int a[205];

int main()
{
	int n,ans=0;
	scanf("%d",&n);
	for(int i=1; i<=2*n; i++) scanf("%d",&a[i]);
	sort(a+1,a+2*n+1);
	for(int i=1; i<=n; i++)
	{
		ans+=a[i*2-1];
	}
	printf("%d\n",ans);
 	return 0;
}
