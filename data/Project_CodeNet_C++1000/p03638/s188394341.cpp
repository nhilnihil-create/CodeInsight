#include<iostream>
#include<cstring>
using namespace std;
int H,W,N,cl[10001],h[101][101];
int xx,yy,ff;
int main()
{
	memset(h,0,sizeof(h));
	cin>>H>>W>>N;
	for(int i=1;i<=N;i++)
		cin>>cl[i];
	xx=0,yy=0,ff=0;
	for(int i=1;i<=N;i++)
	{
		while(cl[i]>0)
		{
			h[xx][yy]=i;
			if (ff==0)
			{
				if(yy+1<W&&h[xx][yy+1]==0)yy++;
				else {ff=1;xx++;}
			}
			else if (ff==1)
			{
				if(xx+1<H&&h[xx+1][yy]==0)xx++;
				else {ff=2;yy--;}
			}
			else if (ff==2)
			{
				if(yy>0&&h[xx][yy-1]==0)yy--;
				else {ff=3;xx--;}
			}
			else if (ff==3)
			{
				if(xx>0&&h[xx-1][yy]==0)xx--;
				else {ff=0;yy++;}
			}
			cl[i]--;
		}
	}
	for(int i=0;i<H;i++)
	{
		for(int j=0;j<W;j++)
		{
			if(j!=0)printf(" ");
			printf("%d",h[i][j]);
		}
		printf("\n");
	}

}