#include<iostream>
#include<cstdio>

const char clr[5]="RYGB";

int main()
{
	int i,j;
	int H,W,d;
	scanf("%d%d%d",&H,&W,&d);
	for(i=0;i<H;i++)
	{
		for(j=0;j<W;j++)
		{
			int x=((i+j)%(2*d)+(2*d))%(2*d)/d;
			int y=((i-j)%(2*d)+(2*d))%(2*d)/d;
		    putchar(clr[x+y*2]);
		}
		putchar('\n');
	}
	return 0;
}