#include <iostream>
#include <cmath>
#include<algorithm>
using namespace std;
int a[200005];
long long int s[200005],r[200005],m[200005],sum=0;
int main()
{
	int n;
	r[0]=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	    {
		scanf("%d",&a[i]);
	    sum=sum+a[i];
	    s[i]=s[i-1]+a[i];
	    }
	for(int j=1;j<n;j++)
	{
		r[j]=sum-s[j];
		m[j]=abs(s[j]-r[j]);
	}
	sort(m,m+n);
	printf("%d\n",m[1]);
}