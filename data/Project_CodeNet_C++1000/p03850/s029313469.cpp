#include <bits/stdc++.h>
typedef long long ll;

int n,i=1,x;
ll a,b=-1e18,c=b;

int main()
{
	scanf("%d%lld",&n,&a);
	for(char o;i<n;++i)
	{
		if(scanf(" %c%d",&o,&x),o=='-')a=b=std::max(a-x,c=b+x);
		else a+=x,b=std::max(b-x,c+=x);
	}
	return printf("%lld\n",a),0;
}
