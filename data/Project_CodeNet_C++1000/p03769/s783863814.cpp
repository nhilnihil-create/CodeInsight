#include<stdio.h>
#include<bits/locale_facets.h>
#include<algorithm>
using namespace std;
const int s=101;
int l[s],r[s],ls,rs;
long long input();
void output(long long value);
int main()
{
	int dep=100;
	ls=rs=0;
	for(long long n=input()+1;n!=1;)
	{
		if(n&1)n--,l[++ls]=dep--;
		n>>=1,r[++rs]=dep--;
	}
	output((ls+rs)<<1),putchar('\n');
	for(int i=1;i<=ls;i++)
	output(l[i]-dep),putchar(' ');
	for(int i=rs;i;i--)
	output(r[i]-dep),putchar(' ');
	dep=100-dep;
	for(int i=1;i<dep;i++)
	output(i),putchar(' ');
	output(dep),putchar('\n');
	return 0;
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