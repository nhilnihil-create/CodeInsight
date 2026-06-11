#include <bits/stdc++.h>
#define L long long

using namespace std;

L h,w,d;
L a[1555][1555];

char ct[]={'R','G','B','Y'};

L ok(L x,L y){
	return 1<=x&&x<=h&&1<=y&&y<=w;
}



int main()
{
	scanf("%lld %lld %lld",&h,&w,&d);
	L i,j,k,l;
	if(d%2)
	{
		for(i=1;i<=h;i++)
		{
			for(j=1;j<=w;j++)
			{
				printf("%c",(i+j)%2?'R':'B');
			}
			puts("");
		}
		return 0;
	}
	L hf=d/2,det;
	for(i=1;(i-2)*hf+1<=h;i++)
	{
		for(j=0;(j-1)*hf+1<=w;j++)
		{
			L x=j;
			if(i%4>=2) x+=2;
			
			if((i+j)%2) continue;
			if(i%2==1&&x%4==1) det=1;
			else if(i%2==0&&x%4==2) det=2;
			else if(x%4==3) det=3;
			else det=4;
			for(k=0;k<hf;k++)
			{
				for(l=(j-1)*hf+1+k;l<=(j-1)*hf+d-k;l++)
				{
					if(ok((i-1)*hf+1-k,l))
						a[(i-1)*hf+1-k][l]=det;
					if(ok((i-1)*hf+1+k,l))
						a[(i-1)*hf+1+k][l]=det;
				}
			}
		}
	
	}
	
			
	for(i=1;i<=h;i++)
	{
		for(j=1;j<=w;j++)
		{
			printf("%c",ct[a[i][j]-1]);
		}
		puts("");
	}
	
}