#include<stdio.h>
#include<bits/locale_facets.h>
#include<algorithm>
using namespace std;
int answer[501][501];
long long input();
void output(long long value);
int main()
{
	int H=input(),W=input(),h=input(),w=input(),k,v,sum=0;
	if(!(H%h)&&!(W%w))return puts("No"),0;
	k=250000/(h*w),v=-k*(h*w-1)-1;
	for(int i=1;i<=H;i++)
	for(int j=1;j<=W;j++)
	{
		if(!(i%h)&&!(j%w))answer[i][j]=v;
		else answer[i][j]=k;
		sum+=answer[i][j];
	}
	if(sum>0)
	{
		puts("Yes");
		for(int i=1;i<=H;i++)
		{
			for(int j=1;j<W;j++)
			output(answer[i][j]),putchar(' ');
			output(answer[i][W]),putchar('\n');
		}
		return 0;
	}
	else return puts("No"),0;
}
long long input()
{
	long long value=0,positive=1;
	char digit=getchar();
	for(;!isdigit(digit);digit=getchar())
	if(digit=='-')positive=-positive;
	for(;isdigit(digit);digit=getchar())value=(value<<3)+(value<<1)+digit-'0';
	return positive*value;
}
void output(long long value)
{
	if(value<0)
	{
		putchar('-');
		value=-value;
	}
	if(value>=10)output(value/10);
	putchar(value%10+'0');
}