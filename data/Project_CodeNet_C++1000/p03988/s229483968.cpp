#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N=110;
int c[N];

int main()
{
	int k=0,n;scanf("%d",&n);
	for(int i=1,x;i<=n;++i) scanf("%d",&x),++c[x],k=max(k,x);
	bool ok=true;
	if(k&1)
	{
		for(int i=k;i>=(k+1)/2;--i) 
		{
			c[i]-=2;
			if(c[i]<0){ok=false;break;};
		};
		for(int i=1;i<(k+1)/2+1;++i) 
			if(c[i]>0){ok=false;break;};
	}else
	{
		for(int i=k;i>=k/2+1;--i)
		{
			c[i]-=2;
			if(c[i]<0){ok=false;break;};
		};
		if(--c[k/2]<0) ok=false;
		for(int i=1;i<k/2+1;++i) 
			if(c[i]>0){ok=false;break;};
	};
	puts(ok?"Possible":"Impossible");
	return 0;
}