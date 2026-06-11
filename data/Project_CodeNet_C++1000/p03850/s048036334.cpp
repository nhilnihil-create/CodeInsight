#include <bits/stdc++.h>
using namespace std;
int x,n;char o;long long a,b=-1e18,c=-1e18;
int main()
{
	scanf("%d%lld",&n,&a);
	for(int i=1;i<n;i++){scanf(" %c%d",&o,&x);if(o=='-') a=b=max(a-x,(c=b+x));else a+=x,b=max(b-x,c+=x);}
	printf("%lld\n",a);
}