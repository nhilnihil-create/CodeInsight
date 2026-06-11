#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#define MAX_N 200005
#define INF 1000000000000000ll
#define int long long

using namespace std;

int n,ans=INF;
int a[MAX_N];

signed main()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]),a[i]+=a[i-1];
	for(int i=1;i<n;i++) ans=min(ans,abs((a[i]<<1)-a[n]));
	printf("%lld\n",ans);
}
