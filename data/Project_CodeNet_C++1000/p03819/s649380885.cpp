#include<iostream>
#include<cstdio>
using namespace std;
int n,m;
int s[1<<17],a;
main()
{
	scanf("%d%d",&n,&m);
	for(;n--;)
	{
		int A,B;scanf("%d%d",&A,&B);
		int M=1;
		for(;M*M<=B;M++)
		{
			if((A+M-1)/M<=B/M)
			{
				s[M]++;
				s[M+1]--;
			}
		}
		int B1=M;
		int k=B/M;
		for(;k>=1;k--)
		{
			int B2=B/k;
			int L=(A+k-1)/k;
			if(L<B1)L=B1;
			s[L]++;
			s[B2+1]--;
			B1=B2+1;
		}
	}
	for(int i=1;i<=m;i++)printf("%d\n",a+=s[i]);
}