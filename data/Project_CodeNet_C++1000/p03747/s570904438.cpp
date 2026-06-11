#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int L,n,T,w[100005],g,i,j,k;
int main()
{
	scanf("%d%d%d",&n,&L,&T);
	for(i=1;i<=n;++i)
	{
		scanf("%d%d",&j,&k);
		if(k==1)
		{
			w[i]=(j+T)%L;
			if(j+T%L>=L)
				++g;
			g+=T/L;
		}
		else
		{
			w[i]=(j-T%L+L)%L;
			if(j-T%L<0)
				--g;
			g-=T/L;
		}
	}
	sort(w+1,w+1+n);
	g=(g%n+n)%n;
	for(i=1;i<=n;++i)
		printf("%d\n",w[i+g<1?n+i+g:i+g<=n?i+g:i+g-n]);
	return 0;
}
