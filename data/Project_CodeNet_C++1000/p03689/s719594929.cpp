#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
#define per(i,n) for ((i)=n;(i)>=(1);(i)--)
using namespace std;
int n,m,a,b,i,j;
int main()
{
	cin>>n>>m>>a>>b;
	if(n%a==0&&m%b==0)
	{
		puts("No");
		return 0;
	}
	puts("Yes");
	rep(i,n)
	{
		rep(j,m)
		{
			if(i%a==0&&j%b==0) printf("%d ",-(500*(a*b-1)+1)); else printf("500 ");
		}
		puts("");
	}
	return 0;
}