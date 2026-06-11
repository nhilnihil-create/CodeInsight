#include<cstdio>
#include<cstring>
#include<iostream>
#include<queue>
#include<map>
#include<cstdlib>
#include<stack>
#include<algorithm>
#include<set>
#include<cmath>
#include<vector>
using namespace std;
int main()
{
	#ifdef local
	freopen("1.txt","r",stdin);
	#endif
	int n;
	long long a[200006];
	scanf("%d",&n);
	int i;
	scanf("%lld",&a[0]);
	for(i=1;i<n;i++)
	scanf("%lld",&a[i]),a[i]+=a[i-1];
	long long mn=0x3f3f3f3f3f3f3f3f;
	for(i=0;i<n-1;i++)
	{
		mn=min(mn,abs(a[n-1]-2*a[i]));
	}
	printf("%lld",mn);
}