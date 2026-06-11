#include<bits/stdc++.h>
using namespace std;
long long a,b,c,d,n,dif,dif2,con[500005][2],r;
bool p=false;
int main()
{
	scanf("%lld %lld %lld %lld %lld",&n,&a,&b,&c,&d);
	dif=abs(a-b);
	dif2=abs(c-d);
	n-=1;
	r=(n)/2;
	for(int i=n%2;i<=n;i+=2)
	{
		con[i][0]=(c*i)-(r*dif2);
		con[i][1]=(d*i)+(r*dif2);
		//printf("%lld %lld ----%d / %d\n",con[i][0],con[i][1],i,r);
		r--;
		if(dif>=con[i][0]&&dif<=con[i][1])
		{
			p=true;		
		}
	}
	/*if(n%2==0)
	{
		con[0][0]=0;
		con[0][1]=dif2*((n)/2);
		printf("%lld %lld ----%d\n",con[0][0],con[0][1],0);
	}*/
	if(p)printf("YES");
	else printf("NO");
}
