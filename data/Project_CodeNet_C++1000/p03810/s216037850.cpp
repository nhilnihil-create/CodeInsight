#include <bits/stdc++.h>
#define N 200010
using namespace std;

inline int read()
{
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0'; ch=getchar();}
	return x*f;
}
int n,A[N],nw=0,winner;
int main()
{
	n=read(); for(int i=1;i<=n;i++) A[i]=read();
	while(1)
	{
		int ct0,ct1; ct0=ct1=0;
		for(int i=1;i<=n;i++)
			ct0+=!(A[i]&1),ct1+=A[i]&1;
		if(ct0&1) {winner=nw; break;}
		else if(ct1>1)
		{
			winner=nw^1; break;
		}
		else 
		{
			int td=0;
			for(int i=1;i<=n;i++)
				if(A[i]&1) td=i;
			if(A[td]==1)
			{
				winner=nw^1; break;
			}
			A[td]--; int xs=A[1];
			for(int i=2;i<=n;i++)
				xs=__gcd(xs,A[i]);
			for(int i=1;i<=n;i++) A[i]/=xs;
		}
		nw^=1;
	}
	if(!winner) puts("First");
	else puts("Second");
}