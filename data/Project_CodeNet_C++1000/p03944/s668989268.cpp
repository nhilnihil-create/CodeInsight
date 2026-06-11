#include <bits/stdc++.h>
using namespace std;
#define ll long long 


int main()
{
	ll i, j, n, m, t, w, h, yh, yl, xh, xl;

	scanf("%lld %lld %lld", &w, &h, &n);

	yh=h, yl=0, xh=w, xl=0;

	for(i=0; i<n; i++)
	{
		ll a, x, y;
		scanf("%lld %lld %lld", &x, &y, &a);
		if(a==1) xl=max(xl, x);
		if(a==2) xh=min(xh, x);
		if(a==3) yl=max(yl, y);
		if(a==4) yh=min(yh, y);
	}

	//printf("%lld\n", xh);

	if(xh<=xl || yh<=yl)
	{
		printf("0\n");
	}
	else
	{
		printf("%lld\n", (xh-xl)*(yh-yl));
	}




	return 0;
}