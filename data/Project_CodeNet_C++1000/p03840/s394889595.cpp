#include <bits/stdc++.h>
#define int long long
using namespace std;
int a,b,c,d,add,ans;
int x[10];
signed main(){
	for (register int i=1; i<=7; ++i) scanf("%lld",&x[i]);
	a=x[1]; b=x[2]; c=x[4]; d=x[5];
	ans=b;
	add=a/2*2+c/2*2+d/2*2;
	if (a && c && d)
	{
		if (a%2==c%2 && a%2==d%2) add=max(add,a+c+d);
		else add=max(add,a+c+d-1);
	}
	ans+=add;
	printf("%lld\n",ans);
return 0;
}