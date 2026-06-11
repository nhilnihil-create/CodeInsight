#include <bits/stdc++.h>
using namespace std;
int n,a[200010],b[200010];
bool check(int now)
{
	for (int i=1;i<=2*n-1;i++)
	  if (a[i]>=now) b[i]=1;else b[i]=0;
	int m=(2*n-1)/2+1;
	int k=-1,Min=1e9;
	for (int i=1;i<=2*n-1;i++)
	  if (i!=1&&b[i]==b[i-1]&&min(abs(i-m)+1,abs(i-1-m)+1)<Min) 
	    Min=min(abs(i-m)+1,abs(i-1-m)+1),k=b[i];
	if (k==-1)
	{
		if (n&1) return b[m];
		else return !b[m];
    }
    return k;
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=2*n-1;i++)
	  scanf("%d",&a[i]);
	int l=1,r=2e5;
	while (l+1<r)
	{
		int mid=(l+r)>>1;
		if (check(mid)) l=mid;
		else r=mid-1;
    }
    if (check(r)) printf("%d\n",r);else printf("%d\n",l);
    return 0;
}