#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,x,i,j,k,prt[200005];
bool v[200005];
int main()
{
	scanf("%d%d",&n,&x);
	if(n==2)
	{
		if(x==2)
			printf("Yes\n1\n2\n3");
		else
			printf("No");
		return 0;
	}
	if(x>1&&x<2*n-1)
	{
		prt[n]=x;
		prt[n-1]=1,prt[n+1]=2*n-1;
		v[x]=v[1]=v[2*n-1]=true;
		if(x>2)
			prt[n+2]=2,v[2]=true;
		else
			prt[n-2]=2*n-2,v[2*n-2]=true;
		for(i=1,j=1;i<=2*n-1;++i)
			if(!prt[i])
			{
				while(v[j])
					++j;
				prt[i]=j++;
			}
		puts("Yes");
		for(i=1;i<=2*n-1;++i)
			printf("%d\n",prt[i]);
		return 0;
	}
	printf("No");
	return 0;
}
